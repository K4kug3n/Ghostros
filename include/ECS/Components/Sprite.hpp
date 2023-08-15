#ifndef ECS_COMPONENTS_SPRITE_HPP
#define ECS_COMPONENTS_SPRITE_HPP

#include <SFML/Graphics/Sprite.hpp>

#include "Graphics/Texture.hpp"
#include "Maths/Vector2.hpp"

template<typename T> class Vector3;
using Vector3f = Vector3<float>;

class Sprite
{
public:
	Sprite() = delete;
	Sprite(Texture texture);
	Sprite(Sprite&& other) noexcept;
	Sprite(const Sprite&) = delete;
	~Sprite() = default;

	const sf::Sprite& get_handle() const;
	void set_position(const Vector3f& position);
	void set_size(const Vector2u& size);

	Sprite& operator=(Sprite&& other) noexcept;
	Sprite& operator=(const Sprite&) = delete;

private:
	Texture m_texture;
	Vector2u m_size;

	sf::Sprite m_sprite;
};

#endif