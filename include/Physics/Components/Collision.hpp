#ifndef ECS_COLLISION_HPP
#define ECS_COLLISION_HPP

#include "ECS/EntityHandler.hpp"
#include "Maths/Vector2.hpp"

class Collision
{
public:
	Collision() = delete;
	Collision(EntityHandler collider, Vector2f position);
	Collision(Collision&&) = default;
	Collision(const Collision&) = default;
	~Collision() = default;

	const EntityHandler& get_collider() const;
	const Vector2f& get_posititon() const;

	Collision& operator=(Collision&&) = default;
	Collision& operator=(const Collision&) = default;

private:
	EntityHandler m_collider;
	Vector2f m_position;
};

#endif