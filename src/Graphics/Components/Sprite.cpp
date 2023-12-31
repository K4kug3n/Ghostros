#include "Graphics/Components/Sprite.hpp"

#include "Maths/Vector3.hpp"

#include "Graphics/Texture.hpp"

Sprite::Sprite(RessourceHandle<Texture> texture)
	: m_texture(std::move(texture))
	, m_size(m_texture->get_size())
	, m_sprite(m_texture->get_handle())
{
}

Sprite::Sprite(Sprite&& other) noexcept
	: m_texture(std::move(other.m_texture))
	, m_size(std::move(other.m_size))
	, m_sprite(std::move(other.m_sprite))
{
}

const sf::Sprite& Sprite::get_handle() const
{
	return m_sprite;
}

void Sprite::set_position(const Vector3f& position)
{
	m_sprite.setPosition(position.x, position.y);
}

void Sprite::set_size(const Vector2u& size)
{
	const Vector2f factor = size.as<float>() / m_size.as<float>();

	m_sprite.setScale(factor.x, factor.y);
}

void Sprite::set_texture(RessourceHandle<Texture> texture)
{
	m_size = texture->get_size();
	m_sprite.setTexture(texture->get_handle());
	m_texture = std::move(texture);
}

void Sprite::set_texture_rect(const Vector2u& top_left, Vector2u size)
{
	m_size = std::move(size);
	m_sprite.setTextureRect(sf::IntRect{ static_cast<int>(top_left.x), static_cast<int>(top_left.y), static_cast<int>(m_size.x), static_cast<int>(m_size.y) });
}

Sprite& Sprite::operator=(Sprite&& other) noexcept
{
	m_texture = std::move(other.m_texture);
	m_size = std::move(other.m_size);
	m_sprite = std::move(other.m_sprite);

	return *this;
}
