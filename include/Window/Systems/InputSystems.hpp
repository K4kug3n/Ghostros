#ifndef WINDOW_SYSTEMS_INPUTSYSTEM_HPP
#define WINDOW_SYSTEMS_INPUTSYSTEM_HPP

#include "ECS/System.hpp"

#include "Window/Components/Input.hpp"

class InputSystem : public System
{
public:
	InputSystem(World& world, InputHandler& input_handler);
	InputSystem(InputSystem&&) = default;
	InputSystem(const InputSystem&) = delete;
	~InputSystem() = default;

	void update(double) override;

	InputSystem& operator=(InputSystem&&) = default;
	InputSystem& operator=(const InputSystem&) = delete;
private:
	Input get_current_input() const;

	InputHandler& m_input_handler;
};

#endif