#include "Physics/Components/Collision.hpp"

Collision::Collision(EntityHandler collider, Vector2f position)
	: m_collider(std::move(collider))
	, m_position(std::move(position))
{
}

const EntityHandler& Collision::get_collider() const
{
	return m_collider;
}

const Vector2f& Collision::get_posititon() const
{
	return m_position;
}
