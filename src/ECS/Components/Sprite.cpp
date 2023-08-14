#include "ECS/Components/Sprite.hpp"

#include "Maths/Vector3.hpp"

Sprite::Sprite(Texture texture)
	: m_texture(std::move(texture))
	, m_size(m_texture.get_width(), m_texture.get_height())
	, m_sprite(m_texture.get_handle())
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
