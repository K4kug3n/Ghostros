#ifndef ECS_COMPONENTS_SPRITE_HPP
#define ECS_COMPONENTS_SPRITE_HPP

#include <SFML/Graphics/Sprite.hpp>

#include "Graphics/Texture.hpp"

class Sprite
{
public:
	Sprite() = delete;
	Sprite(Texture texture);
	Sprite(Sprite&&) = default;
	Sprite(const Sprite&) = delete;
	~Sprite() = default;

	const sf::Sprite& get_handle() const;

	Sprite& operator=(Sprite&&) = default;
	Sprite& operator=(const Sprite&) = delete;

private:
	Texture m_texture;

	sf::Sprite m_sprite;
};

#endif