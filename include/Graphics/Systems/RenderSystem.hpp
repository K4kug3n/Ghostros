#ifndef GRAPHICS_SYSTEMS_RENDERSYSTEM_HPP
#define GRAPHICS_SYSTEMS_RENDERSYSTEM_HPP

#include "ECS/System.hpp"

#include "Graphics/RenderWindow.hpp"

class RenderSystem : public System
{
public:
	RenderSystem(World& world, RenderWindow& window);
	RenderSystem(RenderSystem&&) = default;
	RenderSystem(const RenderSystem&) = delete;
	~RenderSystem() = default;

	void update(double) override;

	RenderSystem& operator=(RenderSystem&&) = default;
	RenderSystem& operator=(const RenderSystem&) = delete;

private:
	RenderWindow& m_window;
};

#endif