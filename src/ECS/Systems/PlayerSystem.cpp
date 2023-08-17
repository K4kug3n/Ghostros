#include "ECS/Systems/PlayerSystem.hpp"

#include "ECS/World.hpp"
#include "ECS/Components/State.hpp"

#include "Window/Components/Input.hpp"

#include "Physics/Components/RigidBody.hpp"

PlayerSystem::PlayerSystem(World& world)
	: System(world)
{
}

void PlayerSystem::update(double)
{
	m_world.view<const Input, State, RigidBody>().each(
		[](const Input input, State& state, RigidBody& body)
		{
			switch(input)
			{
			case Input::DOWN:
				break;

			case Input::UP:
				body.jump = true;
				state = State::JUMP;
				break;

			case Input::LEFT:
				body.velocity.x -= 50.f;
				break;

			case Input::RIGHT:
				body.velocity.x += 50.f;
				break;

			default:
				break;
			}
		}
	);
}
