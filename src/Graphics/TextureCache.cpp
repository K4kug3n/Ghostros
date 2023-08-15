#include "Graphics/TextureCache.hpp"

TextureHandle TextureCache::get(const std::filesystem::path& filepath)
{
	std::string key = std::filesystem::absolute(filepath).generic_string();
	if (m_cache.count(key) != 0)
	{
		std::weak_ptr<Texture>& weak_texture = m_cache[key];
		if (auto texture = weak_texture.lock())
		{
			return TextureHandle{ std::move(texture) };
		}
	}

	std::shared_ptr<Texture> texture = std::make_shared<Texture>(filepath);
	m_cache[key] = texture;

	return TextureHandle{ std::move(texture) };
}
