#ifndef WIDGETS_VERTCIALLAYOUT_HPP
#define WIDGETS_VERTCIALLAYOUT_HPP

#include "Widgets/Layout.hpp"

class VerticalLayout : public Layout
{
public:
	VerticalLayout() = default;
	VerticalLayout(const VerticalLayout&) = delete;
	VerticalLayout(VerticalLayout&&) = default;
	~VerticalLayout() = default;

	VerticalLayout& operator=(const VerticalLayout&) = delete;
	VerticalLayout& operator=(VerticalLayout&&) = default;

protected:
	void update_widgets_position(const Vector2u& position, const Vector2u& size) override;
};

#endif