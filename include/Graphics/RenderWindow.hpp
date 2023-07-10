#ifndef GRAPHICS_RENDERWINDOW_HPP
#define GRAPHICS_RENDERWINDOW_HPP

#include <string>
#include <optional>

#include <SFML/Graphics/RenderWindow.hpp>

#include "Window/InputEvent.hpp"
#include "Maths/Vector2.hpp"

class Camera;

class RenderWindow
{
public:
	RenderWindow() = delete;
	RenderWindow(unsigned width, unsigned height, std::string_view title);
	RenderWindow(const RenderWindow&) = delete;
	RenderWindow(RenderWindow&&) = default;
	~RenderWindow() = default;

	void clear();
	void close();
	void display();
	void draw(const sf::Drawable& drawable, const sf::RenderStates& states = sf::RenderStates::Default);
	Vector2u get_size() const;
	bool is_open() const;
	std::optional<Input::Event> poll_event();
	void set_camera(const Camera& camera);
	void set_title(std::string_view title);

	RenderWindow& operator=(const RenderWindow&) = delete;
	RenderWindow& operator=(RenderWindow&&) = default;

private:
	sf::RenderWindow m_handle;
};


#endif