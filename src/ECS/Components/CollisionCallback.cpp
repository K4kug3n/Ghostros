#include "ECS/Components/CollisionCallback.hpp"

CollisionCallback::CollisionCallback(std::function<void(const EntityHandler&, const EntityHandler&, const Vector2f&)> callback)
	: m_callback(std::move(callback))
{
}

void CollisionCallback::trigger(const EntityHandler& self, const EntityHandler& collider, const Vector2f& position) const
{
	m_callback(self, collider, position);
}
