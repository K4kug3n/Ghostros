#ifndef GRAPHICS_COMPONENTS_CAMERA_HPP
#define GRAPHICS_COMPONENTS_CAMERA_HPP

#include <SFML/Graphics/View.hpp>

template<typename T> class Vector2;
using Vector2u = Vector2<unsigned>;

class Camera
{
public:
	Camera() = default;
	Camera(const Camera&) = delete;
	Camera(Camera&& other) noexcept;
	~Camera() = default;

	sf::View& get_view();
	const sf::View& get_view() const;
	void set_size(const Vector2u& size);

	Camera& operator=(const Camera&) = delete;
	Camera& operator=(Camera&& other) noexcept;

private:
	sf::View m_view;
};

#endif