#include "Physics/Components/RigidBody.hpp"

#include <utility>

RigidBody::RigidBody()
	: velocity(0.f, 0.f)
	, on_ground(false)
	, jump(false)
{
}
