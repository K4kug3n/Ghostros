#include "ECS/EntityHandler.hpp"

EntityHandler::EntityHandler(World& world, entt::entity entity)
	: m_world(&world)
	, m_entity(std::move(entity))
{
}
