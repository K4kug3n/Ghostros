#include "Graphics/Systems/RenderSystem.hpp"

#include "Graphics/RenderWindow.hpp"

#include "ECS/Components/Node.hpp"
#include "ECS/Components/Sprite.hpp"
#include "ECS/World.hpp"

RenderSystem::RenderSystem(World& world)
	: System(world)
{
}

void RenderSystem::update(RenderWindow& window, InputHandler&, double)
{
	auto view = m_world.view<Node, Sprite>();
	view.each([&window](Node& node, Sprite& sprite)
		{
			sprite.set_position(node.position);
			window.draw(sprite.get_handle());
		}
	);
}
