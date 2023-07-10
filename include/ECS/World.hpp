#ifndef ECS_WORLD_HPP
#define ECS_WORLD_HPP

#include <entt/entity/registry.hpp>

#include "Graphics/SceneItem.hpp"

class EntityHandler;

class World : public SceneItem
{
public:
	World() = default;
	World(const World&) = delete;
	World(World&&) = default;
	~World() = default;

	EntityHandler create();
	void update(RenderWindow& window, InputHandler& input_handler, double delta_time) override;

	World& operator=(const World&) = delete;
	World& operator=(World&&) = default;

	friend class EntityHandler;
private:
	entt::registry& get_registry();

	entt::registry m_registry;
};

#endif