#ifndef GRAPHICS_SYSTEMS_ANIMATIONSYSTEM_HPP
#define GRAPHICS_SYSTEMS_ANIMATIONSYSTEM_HPP

#include "ECS/System.hpp"

class AnimationSystem : public System
{
public:
	AnimationSystem() = default;
	AnimationSystem(World& world);
	AnimationSystem(const AnimationSystem&) = delete;
	AnimationSystem(AnimationSystem&&) = default;
	~AnimationSystem() = default;

	void update(double delta_t) override;

	AnimationSystem& operator=(const AnimationSystem&) = delete;
	AnimationSystem& operator=(AnimationSystem&&) = default;

private:
};

#endif