#ifndef ECS_ENTITYHANDLER_HPP
#define ECS_ENTITYHANDLER_HPP

#include <entt/entity/entity.hpp>

#include "ECS/World.hpp"

class EntityHandler
{
public:
	EntityHandler(World& world, entt::entity entity);
	EntityHandler(const EntityHandler&) = delete;
	EntityHandler(EntityHandler&&) = default;
	~EntityHandler() = default;

	template<typename T, typename... Args>
	T& add_compoment(Args... args);

	EntityHandler& operator=(const EntityHandler&) = delete;
	EntityHandler& operator=(EntityHandler&&) = default;

	friend class World;
private:
	entt::entity m_entity;
	World& m_world;
};

#include "ECS/EntityHandler.inl"

#endif
