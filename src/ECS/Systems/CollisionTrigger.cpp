#include "ECS/Systems/CollisionTrigger.hpp"

#include "Physics/Components/Collision.hpp"
#include "ECS/Components/CollisionCallback.hpp"

CollisionTrigger::CollisionTrigger(World& world)
	: System(world)
{
}

void CollisionTrigger::update(RenderWindow&, InputHandler&, double)
{
	auto trigger_view = m_world.view<const Collision, const CollisionCallback>();
	trigger_view.each(
		[this](const auto entity, const Collision& collision, const CollisionCallback& callback)
		{
			callback.trigger(EntityHandler{ m_world, entity }, collision.get_collider(), collision.get_posititon());
		}
	);
}
