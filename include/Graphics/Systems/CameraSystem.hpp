#ifndef GRAPHICS_SYSTEMS_CAMERASYSTEM_HPP
#define GRAPHICS_SYSTEMS_CAMERASYSTEM_HPP

#include "ECS/System.hpp"

class CameraSystem : public System
{
public:
	CameraSystem(World& world, RenderWindow& window);
	CameraSystem(CameraSystem&&) = default;
	CameraSystem(const CameraSystem&) = delete;
	~CameraSystem() = default;

	void update(double) override;

	CameraSystem& operator=(CameraSystem&&) = default;
	CameraSystem& operator=(const CameraSystem&) = delete;

private:
	RenderWindow& m_window;
};

#endif