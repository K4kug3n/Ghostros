#include "ECS/Components/Sprite.hpp"

Sprite::Sprite(Texture texture)
	: m_texture(std::move(texture))
	, m_sprite(m_texture.get_handle())
{
}

const sf::Sprite& Sprite::get_handle() const
{
	return m_sprite;
}
