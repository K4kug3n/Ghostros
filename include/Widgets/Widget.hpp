#ifndef WIDGETS_WIDGET_HPP
#define WIDGETS_WIDGET_HPP

#include "Maths/Vector2.hpp"

class RenderWindow;
class InputHandler;

class Widget
{
public:
	Widget();
	Widget(Vector2u position, Vector2u size);
	Widget(const Widget&) = delete;
	Widget(Widget&&) = default;
	virtual ~Widget();

	virtual void draw(RenderWindow& render_window) = 0;

	const Vector2u& get_position() const;
	const Vector2u& get_size() const;
	void set_size(Vector2u size);
	void set_position(Vector2u position);

	virtual void update(InputHandler& input_handler) = 0;

	Widget& operator=(const Widget&) = delete;
	Widget& operator=(Widget&&) = default;

protected:
	Vector2u m_position;
	Vector2u m_size;
};

#endif