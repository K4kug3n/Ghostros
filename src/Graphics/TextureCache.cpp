#include "Graphics/TextureCache.hpp"

TextureHandle TextureCache::get(const std::filesystem::path& filepath)
{
	std::string key = std::filesystem::absolute(filepath).generic_string();
	if (m_cache.count(key) == 0)
	{
		std::shared_ptr<Texture> texture = std::make_shared<Texture>(filepath);
		m_cache.insert({ key, texture });

		return TextureHandle{ std::move(texture) };
	}

	std::weak_ptr<Texture>& weak_texture = m_cache[key];
	if (auto texture = weak_texture.lock())
	{
		return TextureHandle{ std::move(texture) };
	}

	std::shared_ptr<Texture> texture = std::make_shared<Texture>(filepath);
	weak_texture = texture;

	return TextureHandle{ std::move(texture) };
}
