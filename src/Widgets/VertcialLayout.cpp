#include "Widgets/VerticalLayout.hpp"

#include "Maths/Vector2.hpp"

#include "Widgets/Widget.hpp"

void VerticalLayout::update_widgets_position(const Vector2u& position, const Vector2u& size)
{
	const unsigned height_per_widget = static_cast<unsigned>(size.y / (static_cast<float>(m_widgets.size()) + 0.2));
	const unsigned widget_h = static_cast<unsigned>(height_per_widget * 0.8f);
	const unsigned space_h = static_cast<unsigned>(height_per_widget * 0.2f);

	for (size_t i = 0; i < m_widgets.size(); ++i)
	{
		m_widgets[i]->set_size({size.x, widget_h});

		m_widgets[i]->set_position({ position.x, position.y + space_h + height_per_widget * static_cast<unsigned>(i) });
	}
}
