#include "Physics/Components/RigidBody.hpp"

RigidBody::RigidBody(float mass)
	: mass(mass)
	, velocity(0.f, 0.f)
	, force(0.f, 0.f)
{
}
