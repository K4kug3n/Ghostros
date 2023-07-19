#include "Physics/Systems/PhysicsSpace.hpp"

#include <utility>

#include "ECS/World.hpp"
#include "ECS/Components/Node.hpp"
#include "Physics/Components/RigidBody.hpp"

PhysicsSpace::PhysicsSpace(World& world)
	: System(world)
	, m_gravity(0.f, 0.f)
{
}

void PhysicsSpace::update(RenderWindow&, InputHandler&, double delta_time)
{
	step(static_cast<float>(delta_time));
}

void PhysicsSpace::set_gravity(Vector2f gravity)
{
	m_gravity = std::move(gravity);
}

void PhysicsSpace::step(float dt)
{
	auto view = m_world.view<Node, RigidBody>();

	view.each([this, dt](Node& node, RigidBody& body)
		{
			body.force += body.mass * m_gravity;
			body.velocity += (body.force / body.mass) * dt;
			Vector2f position = body.velocity * dt;
			node.position += Vector3f{ position.x, position.y, 0.f };
		}
	);
}
