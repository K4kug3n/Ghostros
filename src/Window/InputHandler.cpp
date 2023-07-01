#include "Window/InputHandler.hpp"

#include "Window/RenderWindow.hpp"

InputHandler::InputHandler()
{}

bool InputHandler::is_active(const std::string& name) const
{
	auto it = m_registered_actions.find(name);
	if (it != m_registered_actions.end())
	{
		return it->second.is_active(m_pending_events);
	}

	return false;
}

void InputHandler::update(RenderWindow& render_window)
{
	m_pending_events.clear();

	std::optional<Input::Event> event = render_window.poll_event();
	while (event)
	{
		m_pending_events.push_back(event.value());
		event = render_window.poll_event();
	}
}

void InputHandler::register_action(std::string name, Action action)
{
	m_registered_actions.insert_or_assign(std::move(name), std::move(action));
}