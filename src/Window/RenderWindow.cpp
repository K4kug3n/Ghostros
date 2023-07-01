#include "Window/RenderWindow.hpp"

RenderWindow::RenderWindow(unsigned width, unsigned height, const std::string& title)
	: m_handle(sf::VideoMode{ width, height, 32 }, title)
{}

void RenderWindow::display()
{
	m_handle.display();
}

InputHandler& RenderWindow::input_handler()
{
	return m_input_handler;
}

bool RenderWindow::is_open() const
{
	return m_handle.isOpen();
}
