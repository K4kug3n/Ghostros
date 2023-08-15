#ifndef GRAPHICS_TEXTUREHANDLE_HPP
#define GRAPHICS_TEXTUREHANDLE_HPP

#include <memory>
#include "Graphics/Texture.hpp"

class TextureHandle
{
public:
	TextureHandle() = delete;
	TextureHandle(std::shared_ptr<Texture> handle);
	TextureHandle(const TextureHandle&) = default;
	TextureHandle(TextureHandle&&) = default;
	~TextureHandle() = default;

	Texture* operator->() const;

	TextureHandle& operator=(const TextureHandle&) = default;
	TextureHandle& operator=(TextureHandle&&) = default;

private:
	std::shared_ptr<Texture> m_handle;
};

#endif