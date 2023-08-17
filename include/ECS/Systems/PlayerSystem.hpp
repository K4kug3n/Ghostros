#ifndef ECS_SYSTEMS_PLAYERSYSTEM_HPP
#define ECS_SYSTEMS_PLAYERSYSTEM_HPP

#include "ECS/System.hpp"

class PlayerSystem : public System
{
public:
	PlayerSystem(World& world);
	PlayerSystem(PlayerSystem&&) = default;
	PlayerSystem(const PlayerSystem&) = delete;
	~PlayerSystem() = default;

	void update(RenderWindow&, InputHandler&, double) override;

	PlayerSystem& operator=(PlayerSystem&&) = default;
	PlayerSystem& operator=(const PlayerSystem&) = delete;
};

#endif