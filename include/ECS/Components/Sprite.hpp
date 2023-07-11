#ifndef ECS_COMPONENTS_SPRITE_HPP
#define ECS_COMPONENTS_SPRITE_HPP

#include <SFML/Graphics/Sprite.hpp>

#include "Graphics/Texture.hpp"

template<typename T> class Vector3;
using Vector3f = Vector3<float>;

class Sprite
{
public:
	Sprite() = delete;
	Sprite(Texture texture);
	Sprite(Sprite&&) = default;
	Sprite(const Sprite&) = delete;
	~Sprite() = default;

	const sf::Sprite& get_handle() const;
	void set_position(const Vector3f& position);

	Sprite& operator=(Sprite&&) = default;
	Sprite& operator=(const Sprite&) = delete;

private:
	Texture m_texture;

	sf::Sprite m_sprite;
};

#endif