#ifndef GRAPHICS_CAMERA_HPP
#define GRAPHICS_CAMERA_HPP

#include <SFML/Graphics/View.hpp>

template<typename T> class Vector2;
using Vector2u = Vector2<unsigned>;

class Camera
{
public:
	Camera() = delete;
	Camera(const Vector2u& center_pos, const Vector2u& size);
	Camera(unsigned top_left_x, unsigned top_left_y, unsigned bottom_right_x, unsigned bottom_right_y);
	Camera(const Camera&) = delete;
	Camera(Camera&&) = default;
	~Camera() = default;

	sf::View& get_view();
	const sf::View& get_view() const;
	void set_size(const Vector2u& size);

	Camera& operator=(const Camera&) = delete;
	Camera& operator=(Camera&&) = default;

private:
	sf::View m_view;
};

#endif