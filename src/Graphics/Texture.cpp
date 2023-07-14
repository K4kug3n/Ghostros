#include "Graphics/Texture.hpp"

Texture::Texture(const std::filesystem::path& filepath)
	: m_texture()
{
	if (!m_texture.loadFromFile(filepath.generic_string()))
	{
		throw std::runtime_error("Can't load Texture from file " + filepath.generic_string());
	}
}

const sf::Texture& Texture::get_handle() const
{
	return m_texture;
}

unsigned Texture::get_height() const
{
	return m_texture.getSize().y;
}

unsigned Texture::get_width() const
{
	return m_texture.getSize().x;
}
