#ifndef WIDGETS_LAYOUTWIDGET_HPP
#define WIDGETS_LAYOUTWIDGET_HPP

#include "Widgets/Widget.hpp"
#include "Widgets/Layout.hpp"

#include <memory>

class LayoutWidget : public Widget
{
public:
	LayoutWidget() = default;
	LayoutWidget(Vector2u position, Vector2u size);
	LayoutWidget(const LayoutWidget&) = delete;
	LayoutWidget(LayoutWidget&&) = default;
	~LayoutWidget() = default;

	void set_layout(std::unique_ptr<Layout> layout);

	void draw(RenderWindow& render_window) override;
	void update(InputHandler& input_handler) override;

	LayoutWidget& operator=(const LayoutWidget&) = delete;
	LayoutWidget& operator=(LayoutWidget&&) = default;

private:
	std::unique_ptr<Layout> m_layout;
};

#endif