#include "Physics/Components/RigidBody.hpp"

#include <utility>

RigidBody::RigidBody(float mass, Vector2f size)
	: mass(mass)
	, size(std::move(size))
	, velocity(0.f, 0.f)
	, on_ground(false)
	, jump(false)
{
}
