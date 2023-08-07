#ifndef ECS_COLLISIONCALLBACK_HPP
#define ECS_COLLISIONCALLBACK_HPP

#include <functional>

#include "ECS/EntityHandler.hpp"
#include "Maths/Vector2.hpp"

class CollisionCallback
{
public:
	CollisionCallback() = delete;
	CollisionCallback(std::function<void(const EntityHandler&, const EntityHandler&, const Vector2f&)> callback);
	CollisionCallback(CollisionCallback&&) = default;
	CollisionCallback(const CollisionCallback&) = delete;
	~CollisionCallback() = default;

	void trigger(const EntityHandler& self, const EntityHandler& collider, const Vector2f& position) const;

	CollisionCallback& operator=(CollisionCallback&&) = default;
	CollisionCallback& operator=(const CollisionCallback&) = delete;

private:
	std::function<void(const EntityHandler&, const EntityHandler&, const Vector2f&)> m_callback;
};

#endif