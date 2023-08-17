#ifndef PHYSICS_SYSTEMS_PHYSICSSPACE_HPP
#define PHYSICS_SYSTEMS_PHYSICSSPACE_HPP

#include "ECS/System.hpp"
#include "Maths/Vector2.hpp"

class World;
class TileMap;
class RigidBody;
template<typename T> class Vector3;
using Vector3f = Vector3<float>;

class PhysicsSpace : public System
{
public:
	PhysicsSpace(World& world);
	PhysicsSpace(PhysicsSpace&&) = default;
	PhysicsSpace(const PhysicsSpace&) = delete;
	~PhysicsSpace() = default;

	void update(double delta_time) override;
	void set_gravity(Vector2f gravity);
	void step(float dt);

	PhysicsSpace& operator=(PhysicsSpace&&) = default;
	PhysicsSpace& operator=(const PhysicsSpace&) = delete;

private:

	Vector2f m_gravity;
};

#endif