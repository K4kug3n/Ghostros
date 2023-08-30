#include "Graphics/Systems/CameraSystem.hpp"

#include "Graphics/RenderWindow.hpp"
#include "Graphics/Components/Camera.hpp"

#include "ECS/Components/Node.hpp"
#include "ECS/World.hpp"

CameraSystem::CameraSystem(World& world, RenderWindow& window)
	: System(world)
	, m_window(window)
{
}

void CameraSystem::update(double)
{
	const Vector2u& window_size = m_window.get_size();

	auto camera_view = m_world.view<const Node, Camera>();
	camera_view.each(
		[this, &window_size](const Node& node, Camera& camera)
		{
			camera.set_size(window_size);

			sf::View& view = camera.get_view();
			const Vector3f& position = node.get_position();
			view.setCenter(position.x, position.y);
			m_window.set_camera(camera);
		}
	);
}
