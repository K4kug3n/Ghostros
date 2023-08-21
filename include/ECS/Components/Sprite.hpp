#ifndef ECS_COMPONENTS_SPRITE_HPP
#define ECS_COMPONENTS_SPRITE_HPP

#include <SFML/Graphics/Sprite.hpp>

#include "Graphics/TextureHandle.hpp"
#include "Maths/Vector2.hpp"

template<typename T> class Vector3;
using Vector3f = Vector3<float>;

class Sprite
{
public:
	Sprite() = delete;
	Sprite(TextureHandle texture);
	Sprite(Sprite&&) = default;
	Sprite(const Sprite&) = delete;
	~Sprite() = default;

	const sf::Sprite& get_handle() const;
	void set_position(const Vector3f& position);
	void set_size(const Vector2u& size);
	void set_texture(TextureHandle texture);
	void set_texture_rect(const Vector2u& top_left, Vector2u size);

	Sprite& operator=(Sprite&&) = default;
	Sprite& operator=(const Sprite&) = delete;

private:
	TextureHandle m_texture;
	Vector2u m_size;

	sf::Sprite m_sprite;
};

#endif