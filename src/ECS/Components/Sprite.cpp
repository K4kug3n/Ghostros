#include "ECS/Components/Sprite.hpp"

#include "Maths/Vector3.hpp"

Sprite::Sprite(Texture texture)
	: m_texture(std::move(texture))
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
