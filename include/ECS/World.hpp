#ifndef ECS_WORLD_HPP
#define ECS_WORLD_HPP

#include <entt/entity/registry.hpp>

#include "ECS/System.hpp"

class EntityHandler;

class World
{
public:
	World() = default;
	World(const World&) = delete;
	World(World&&) = default;
	~World() = default;

	template<typename T, typename... Args>
	T& add_system(Args&&... args);
	
	EntityHandler create();

	template<typename T>
	void remove(entt::entity entity);

	void update(double delta_time);

	template<typename... Types>
	entt::view< entt::get_t<Types...>> view();

	World& operator=(const World&) = delete;
	World& operator=(World&&) = default;

	friend class EntityHandler;
private:
	entt::registry& get_registry();

	entt::registry m_registry;
	std::vector<std::unique_ptr<System>> m_systems;
};

#include "ECS/World.inl"

#endif
