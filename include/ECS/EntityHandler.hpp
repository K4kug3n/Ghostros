#ifndef ECS_ENTITYHANDLER_HPP
#define ECS_ENTITYHANDLER_HPP

#include <entt/entity/entity.hpp>

#include "ECS/World.hpp"

class EntityHandler
{
public:
	EntityHandler(World& world, entt::entity entity);
	EntityHandler(const EntityHandler&) = default;
	EntityHandler(EntityHandler&&) = default;
	~EntityHandler() = default;

	template<typename T, typename... Args>
	T& add_component(Args... args) const;

	template<typename T, typename... Args>
	T& add_or_replace_component(Args... args) const;

	template<typename T>
	T& get() const;

	template<typename T>
	void remove() const;

	EntityHandler& operator=(const EntityHandler&) = default;
	EntityHandler& operator=(EntityHandler&&) = default;

	friend class World;
private:
	entt::entity m_entity;
	World* m_world;
};

#include "ECS/EntityHandler.inl"

#endif
