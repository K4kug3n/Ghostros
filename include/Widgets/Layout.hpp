#ifndef WIDGETS_LAYOUT_HPP
#define WIDGETS_LAYOUT_HPP

#include <vector>
#include <memory>

class InputHandler;
class RenderWindow;
class Widget;

template<typename T> class Vector2;
using Vector2u = Vector2<unsigned>;

class Layout
{
public:
	Layout() = default;
	Layout(const Layout&) = delete;
	Layout(Layout&&) = default;
	virtual ~Layout();

	template <typename T>
	T* add_widget(std::unique_ptr<T> widget);

	void draw(RenderWindow& render_window);
	void update(InputHandler& input_handler, const Vector2u& position, const Vector2u& size);

	Layout& operator=(const Layout&) = delete;
	Layout& operator=(Layout&&) = default;

protected:
	virtual void update_widgets_position(const Vector2u& position, const Vector2u& size) = 0;

	std::vector<std::unique_ptr<Widget>> m_widgets;
};

#include "Widgets/Layout.inl"

#endif