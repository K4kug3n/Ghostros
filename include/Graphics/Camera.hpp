#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <SFML/Graphics/View.hpp>

template<typename T> class Vector2;
using Vector2u = Vector2<unsigned>;
using Vector2f = Vector2<float>;

class Camera
{
public:
	Camera() = delete;
	Camera(const Vector2u& center_pos, const Vector2u& size);
	Camera(unsigned top_left_x, unsigned top_left_y, unsigned bottom_right_x, unsigned bottom_right_y);
	Camera(const Camera&) = delete;
	Camera(Camera&&) = default;
	~Camera() = default;

	const sf::View& get_view() const;
	void move(const Vector2f& movement);
	void set_size(const Vector2u& size);

	Camera& operator=(const Camera&) = delete;
	Camera& operator=(Camera&&) = default;

private:
	sf::View m_view;
};

#endif