#include "Window/Action.hpp"

ActionEvent::~ActionEvent()
{}

InternalActionKeyboard::InternalActionKeyboard(InputEvent::Keyboard key)
	: m_key(key)
{}

bool InternalActionKeyboard::is_active(const std::vector<InputEvent::Event>& pending_events) const
{
	for (auto&& event : pending_events)
	{
		if (event.type == InputEvent::Window::KeyPressed && event.key.key == m_key)
		{
			return true;
		}
	}

	return false;
}

InternalActionWindow::InternalActionWindow(InputEvent::Window event)
	: m_event(event)
{}

bool InternalActionWindow::is_active(const std::vector<InputEvent::Event>& pending_events) const
{
	for (auto&& event : pending_events)
	{
		if (event.type == m_event)
		{
			return true;
		}
	}

	return false;
}

InternalActionMouse::InternalActionMouse(InputEvent::Mouse button)
	: m_button(button)
{}

bool InternalActionMouse::is_active(const std::vector<InputEvent::Event>& pending_events) const
{
	for (auto&& event : pending_events)
	{
		if (event.type == InputEvent::Window::MouseButtonPressed && event.mouse_button.button == m_button)
		{
			return true;
		}
	}

	return false;
}

Action::Action(InputEvent::Keyboard key)
	: m_action(std::make_unique<InternalActionKeyboard>(key))
{}

Action::Action(InputEvent::Window event)
	: m_action(std::make_unique<InternalActionWindow>(event))
{}

Action::Action(InputEvent::Mouse button)
	: m_action(std::make_unique<InternalActionMouse>(button))
{}

bool Action::is_active(const std::vector<InputEvent::Event>& pending_events) const
{
	return m_action->is_active(pending_events);
}