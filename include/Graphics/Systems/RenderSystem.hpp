#ifndef GRAPHICS_SYSTEMS_RENDERSYSTEM_HPP
#define GRAPHICS_SYSTEMS_RENDERSYSTEM_HPP

#include "ECS/System.hpp"

class World;

class RenderSystem : public System
{
public:
	RenderSystem(World& world);
	RenderSystem(RenderSystem&&) = default;
	RenderSystem(const RenderSystem&) = delete;
	~RenderSystem() = default;

	void update(RenderWindow& window, InputHandler&, double delta_t) override;

	RenderSystem& operator=(RenderSystem&&) = default;
	RenderSystem& operator=(const RenderSystem&) = delete;
};

#endif