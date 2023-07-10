#include "ECS/World.hpp"

#include "ECS/EntityHandler.hpp"

EntityHandler World::create()
{
	entt::entity entity = m_registry.create();
	return EntityHandler(*this, std::move(entity));
}

void World::update(RenderWindow& window, InputHandler& input_handler, double delta_time)
{

}

entt::registry& World::get_registry()
{
	return m_registry;
}
