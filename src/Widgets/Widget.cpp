#include "Widgets/Widget.hpp"

#include <utility>

Widget::Widget()
	: m_position(0u, 0u)
	, m_size(0u, 0u)
{
}

Widget::Widget(Vector2u position, Vector2u size)
	: m_position(std::move(position))
	, m_size(std::move(size))
{
}

Widget::~Widget()
{
}

const Vector2u& Widget::get_position() const
{
	return m_position;
}

const Vector2u& Widget::get_size() const
{
	return m_size;
}

void Widget::set_size(Vector2u size)
{
	m_size = std::move(size);
}

void Widget::set_position(Vector2u position)
{
	m_position = std::move(position);
}
