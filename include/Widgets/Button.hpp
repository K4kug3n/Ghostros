#ifndef WIDGETS_BUTTON_HPP
#define WIDGETS_BUTTON_HPP

#include <string>
#include <functional>

#include "Widgets/Widget.hpp"

#include "Graphics/Components/Sprite.hpp"
#include "Graphics/Components/Text.hpp"

class Button : public Widget
{
public:
	Button() = delete;
	Button(const std::string& text, Vector2u position = { 0u, 0u }, Vector2u size = { 0u, 0u });
	Button(const Button&) = delete;
	Button(Button&&) = default;
	~Button() = default;

	void draw(RenderWindow& render_window) override;
	void on_click(std::function<void()> callback);
	void update(InputHandler& input_handler) override;

	Button& operator=(const Button&) = delete;
	Button& operator=(Button&&) = default;

private:
	Sprite m_sprite;
	Text m_text;

	std::function<void()> m_on_click_callback;
};

#endif