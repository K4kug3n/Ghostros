#include "ECS/World.hpp"

#include "ECS/EntityHandler.hpp"
#include "ECS/System.hpp"

EntityHandler World::create()
{
	entt::entity entity = m_registry.create();
	return EntityHandler(*this, std::move(entity));
}

void World::update(double delta_time)
{
	for(auto&& system : m_systems)
	{
		system->update(delta_time);
	}
}

entt::registry& World::get_registry()
{
	return m_registry;
}
