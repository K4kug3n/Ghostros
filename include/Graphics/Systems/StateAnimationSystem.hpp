#ifndef GRAPHICS_SYSTEMS_STATEANIMATIONSYSTEM_HPP
#define GRAPHICS_SYSTEMS_STATEANIMATIONSYSTEM_HPP

#include "ECS/System.hpp"

class StateAnimationSystem : public System
{
public:
	StateAnimationSystem() = default;
	StateAnimationSystem(World& world);
	StateAnimationSystem(const StateAnimationSystem&) = delete;
	StateAnimationSystem(StateAnimationSystem&&) = default;
	~StateAnimationSystem() = default;

	void update(double) override;

	StateAnimationSystem& operator=(const StateAnimationSystem&) = delete;
	StateAnimationSystem& operator=(StateAnimationSystem&&) = default;

private:
};

#endif