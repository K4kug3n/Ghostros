#include "Window/RenderWindow.hpp"

#include <SFML/Window/Event.hpp>

RenderWindow::RenderWindow(unsigned width, unsigned height, const std::string& title)
	: m_handle(sf::VideoMode{ width, height, 32 }, title)
{}

void RenderWindow::display()
{
	m_handle.display();
}

bool RenderWindow::is_open() const
{
	return m_handle.isOpen();
}

std::optional<Input::Event> RenderWindow::poll_event()
{
	sf::Event event;
	if (m_handle.pollEvent(event))
	{
		return std::make_optional(Input::Event::From(event));
	}

	return std::nullopt;
}
