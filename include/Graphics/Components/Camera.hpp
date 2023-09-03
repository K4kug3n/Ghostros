#ifndef GRAPHICS_COMPONENTS_CAMERA_HPP
#define GRAPHICS_COMPONENTS_CAMERA_HPP

#include <SFML/Graphics/View.hpp>

template<typename T> class Vector2;
using Vector2u = Vector2<unsigned>;
using Vector2f = Vector2<float>;

class Camera
{
public:
	Camera() = default;
	Camera(const Vector2f& position, const Vector2u& size);
	Camera(const Camera&) = delete;
	Camera(Camera&& other) noexcept;
	~Camera() = default;

	sf::View& get_view();
	const sf::View& get_view() const;
	void set_size(const Vector2u& size);
	void set_position(const Vector2f& position);

	Camera& operator=(const Camera&) = delete;
	Camera& operator=(Camera&& other) noexcept;

private:
	sf::View m_view;
};

#endif