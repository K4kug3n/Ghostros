#include "Window/RenderWindow.hpp"

#include <SFML/Window/Event.hpp>

RenderWindow::RenderWindow(unsigned width, unsigned height, const std::string& title)
	: m_handle(sf::VideoMode{ width, height, 32 }, title)
{}

void RenderWindow::clear()
{
	m_handle.clear();
}

void RenderWindow::close()
{
	m_handle.close();
}

void RenderWindow::display()
{
	m_handle.display();
}

void RenderWindow::draw(const sf::Drawable& drawable, const sf::RenderStates& states)
{
	m_handle.draw(drawable, states);
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
