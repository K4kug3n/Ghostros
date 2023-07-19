#include "Graphics/Components/Camera.hpp"

#include "Maths/Vector2.hpp"

Camera::Camera(const Vector2u& center_pos, const Vector2u& size)
	: m_view(sf::Vector2f{ static_cast<float>(center_pos.x), static_cast<float>(center_pos.y) }, sf::Vector2f{ static_cast<float>(size.x), static_cast<float>(size.y) })
{}

Camera::Camera(unsigned top_left_x, unsigned top_left_y, unsigned bottom_right_x, unsigned bottom_right_y)
	: m_view(sf::FloatRect{ static_cast<float>(top_left_x), static_cast<float>(top_left_y), static_cast<float>(bottom_right_x), static_cast<float>(bottom_right_y) })
{}

sf::View& Camera::get_view()
{
	return m_view;
}

const sf::View& Camera::get_view() const
{
	return m_view;
}

void Camera::set_size(const Vector2u& size)
{
	m_view.setSize(static_cast<float>(size.x), static_cast<float>(size.y));
}
