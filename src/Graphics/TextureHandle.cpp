#include "Graphics/TextureHandle.hpp"

TextureHandle::TextureHandle(std::shared_ptr<Texture> handle)
	: m_handle(std::move(handle))
{
}

Texture* TextureHandle::operator->() const
{
	return m_handle.get();
}