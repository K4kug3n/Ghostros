#ifndef GRAPHICS_TEXTURECACHE_HPP
#define GRAPHICS_TEXTURECACHE_HPP

#include <filesystem>
#include <unordered_map>
#include <memory>

#include "Graphics/TextureHandle.hpp"

class TextureCache
{
public:
	TextureCache() = default;
	TextureCache(const TextureCache&) = delete;
	TextureCache(TextureCache&&) = default;
	~TextureCache() = default;

	TextureHandle get(const std::filesystem::path& filepath);

	TextureCache& operator=(const TextureCache&) = delete;
	TextureCache& operator=(TextureCache&&) = default;

private:
	std::unordered_map<std::string, std::weak_ptr<Texture>> m_cache;
};

#endif