#include "Widgets/LayoutWidget.hpp"

#include "Widgets/Layout.hpp"

LayoutWidget::LayoutWidget(Vector2u position, Vector2u size)
	: Widget(position, size)
{
}

void LayoutWidget::set_layout(std::unique_ptr<Layout> layout)
{
	m_layout = std::move(layout);
}

void LayoutWidget::draw(RenderWindow& render_window)
{
	if (m_layout)
	{
		m_layout->draw(render_window);
	}
}

void LayoutWidget::update(InputHandler& input_handler)
{
	if (m_layout)
	{
		const Vector2u padding{ 20u, 20u };
		m_layout->update(input_handler, m_position + padding, m_size - 2u * padding);
	}
}
