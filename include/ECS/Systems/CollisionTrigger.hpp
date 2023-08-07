#ifndef ECS_COLLISIONTRIGGER_HPP
#define ECS_COLLISIONTRIGGER_HPP

#include "ECS/World.hpp"
#include "ECS/System.hpp"

class CollisionTrigger : public System
{
public:
	CollisionTrigger(World& world);
	CollisionTrigger(CollisionTrigger&&) = default;
	CollisionTrigger(const CollisionTrigger&) = delete;
	~CollisionTrigger() = default;

	void update(RenderWindow&, InputHandler&, double) override;

	CollisionTrigger& operator=(CollisionTrigger&&) = default;
	CollisionTrigger& operator=(const CollisionTrigger&) = delete;
};

#endif