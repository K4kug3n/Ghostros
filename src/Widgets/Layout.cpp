#include "Widgets/Layout.hpp"

#include "Widgets/Widget.hpp"

Layout::~Layout()
{
}

void Layout::add_widget(std::unique_ptr<Widget> widget)
{
	m_widgets.emplace_back(std::move(widget));
}

void Layout::draw(RenderWindow& render_window)
{
	for (auto&& widget_ptr : m_widgets)
	{
		widget_ptr->draw(render_window);
	}
}

void Layout::update(InputHandler& input_handler, const Vector2u& position, const Vector2u& size)
{
	update_widgets_position(position, size);

	for (auto&& widget_ptr : m_widgets)
	{
		widget_ptr->update(input_handler);
	}
}
