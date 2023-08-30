#include "Graphics/Components/Camera.hpp"

#include "Maths/Vector2.hpp"

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
