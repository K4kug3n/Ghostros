#include "Graphics/RenderWindow.hpp"

#include <SFML/Window/Event.hpp>

#include "Graphics/Components/Camera.hpp"

RenderWindow::RenderWindow(unsigned width, unsigned height, std::string_view title)
	: m_handle(sf::VideoMode{ width, height, 32 }, title.data())
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

Vector2u RenderWindow::get_size() const
{
	const sf::Vector2u size = m_handle.getSize();
	return Vector2u{ size.x, size.y };
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

void RenderWindow::set_camera(const Camera& camera)
{
	m_handle.setView(camera.get_view());
}

void RenderWindow::set_title(std::string_view title)
{
	m_handle.setTitle(title.data());
}
