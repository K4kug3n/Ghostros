#ifndef WINODW_RENDERWINDOW_HPP
#define WINODW_RENDERWINDOW_HPP

#include <string>

#include <SFML/Graphics/RenderWindow.hpp>

class RenderWindow
{
public:
	RenderWindow() = delete;
	RenderWindow(unsigned width, unsigned height, const std::string& title);
	RenderWindow(const RenderWindow&) = delete;
	RenderWindow(RenderWindow&&) = default;
	~RenderWindow() = default;

	void display();
	bool is_open() const;

	RenderWindow& operator=(const RenderWindow&) = delete;
	RenderWindow& operator=(RenderWindow&&) = default;

private:
	sf::RenderWindow m_handle;
};


#endif