#include "Window/Systems/InputSystems.hpp"

#include "ECS/World.hpp"
#include "Window/InputHandler.hpp"

InputSystem::InputSystem(World& world, InputHandler& input_handler)
	: System(world)
	, m_input_handler(input_handler)
{
}

void InputSystem::update(RenderWindow&, InputHandler&, double)
{
	Input current_input = get_current_input();

	m_world.view<Input>().each(
		[current_input](Input& input)
		{
			input = current_input;
		}
	);
}

Input InputSystem::get_current_input() const
{
	if (m_input_handler.is_active("up"))
	{
		return Input::UP;
	}
	if (m_input_handler.is_active("down"))
	{
		return Input::DOWN;
	}
	if (m_input_handler.is_active("left"))
	{
		return Input::LEFT;
	}
	if (m_input_handler.is_active("right"))
	{
		return Input::RIGHT;
	}

	return Input::NONE;
}
