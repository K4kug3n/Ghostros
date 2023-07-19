#ifndef PHYSICS_COMPONENTS_RIGIDBODY_HPP
#define PHYSICS_COMPONENTS_RIGIDBODY_HPP

#include "Maths/Vector2.hpp"

class RigidBody
{
public:
	RigidBody() = delete;
	RigidBody(float mass);
	RigidBody(RigidBody&&) = default;
	RigidBody(const RigidBody&) = delete;
	~RigidBody() = default;

	RigidBody& operator=(RigidBody&&) = default;
	RigidBody& operator=(const RigidBody&) = delete;

	float mass;
	Vector2f velocity;
	Vector2f force;
};

#endif