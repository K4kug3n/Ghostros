#include "Window/InputHandler.hpp"

#include "Graphics/RenderWindow.hpp"

InputHandler::InputHandler()
	: m_registered_actions()
	, m_pending_events()
	, m_mouse_position(Vector2i{ 0, 0 })
{}

bool InputHandler::is_active(const Action& action) const
{
	return action.is_active(m_pending_events);
}

bool InputHandler::is_active(const std::string& name) const
{
	auto it = m_registered_actions.find(name);
	if (it != m_registered_actions.end())
	{
		return it->second.is_active(m_pending_events);
	}

	return false;
}

const Vector2i& InputHandler::get_mouse_position() const
{
	return m_mouse_position;
}

void InputHandler::update(RenderWindow& render_window)
{
	m_pending_events.clear();

	std::optional<InputEvent::Event> event = render_window.poll_event();
	while (event)
	{
		m_pending_events.push_back(event.value());
		event = render_window.poll_event();
	}

	m_mouse_position = render_window.get_mouse_position();
}

void InputHandler::register_action(std::string name, Action action)
{
	m_registered_actions.insert_or_assign(std::move(name), std::move(action));
}