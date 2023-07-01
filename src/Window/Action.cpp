#include "Window/Action.hpp"

ActionEvent::~ActionEvent()
{}

InternalActionKeyboard::InternalActionKeyboard(Input::Keyboard key)
	: m_key(key)
{}

bool InternalActionKeyboard::is_active(const std::vector<Input::Event>& pending_events) const
{
	for (auto&& event : pending_events)
	{
		if (event.type == Input::Window::KeyPressed && event.key.key == m_key)
		{
			return true;
		}
	}

	return false;
}

InternalActionWindow::InternalActionWindow(Input::Window event)
	: m_event(event)
{}

bool InternalActionWindow::is_active(const std::vector<Input::Event>& pending_events) const
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

InternalActionMouse::InternalActionMouse(Input::Mouse button)
	: m_button(button)
{}

bool InternalActionMouse::is_active(const std::vector<Input::Event>& pending_events) const
{
	for (auto&& event : pending_events)
	{
		if (event.type == Input::Window::MouseButtonPressed && event.mouse_button.button == m_button)
		{
			return true;
		}
	}

	return false;
}

Action::Action(Input::Keyboard key)
	: m_action(std::make_unique<InternalActionKeyboard>(key))
{}

Action::Action(Input::Window event)
	: m_action(std::make_unique<InternalActionWindow>(event))
{}

Action::Action(Input::Mouse button)
	: m_action(std::make_unique<InternalActionMouse>(button))
{}

bool Action::is_active(const std::vector<Input::Event>& pending_events) const
{
	return m_action->is_active(pending_events);
}