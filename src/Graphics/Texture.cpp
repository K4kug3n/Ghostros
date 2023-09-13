#include "Graphics/Texture.hpp"

#include "Maths/Vector2.hpp"

Texture::Texture(const std::filesystem::path& filepath)
	: m_texture()
{
	if (!m_texture.loadFromFile(std::filesystem::absolute(filepath).generic_string()))
	{
		throw std::runtime_error("Can't load Texture from file " + filepath.generic_string());
	}
}

Texture::Texture(Texture&& other) noexcept
	: m_texture(std::move(other.m_texture))
{
}

const sf::Texture& Texture::get_handle() const
{
	return m_texture;
}

unsigned Texture::get_height() const
{
	return m_texture.getSize().y;
}

Vector2u Texture::get_size() const
{
	return Vector2u{ m_texture.getSize().x, m_texture.getSize().y };
}

unsigned Texture::get_width() const
{
	return m_texture.getSize().x;
}

Texture& Texture::operator=(Texture&& other) noexcept
{
	m_texture = std::move(other.m_texture);

	return *this;
}
