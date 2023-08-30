#include "Graphics/Systems/RenderSystem.hpp"

#include "Graphics/RenderWindow.hpp"
#include "Graphics/Components/TileMap.hpp"
#include "Graphics/Components/Sprite.hpp"

#include "ECS/Components/Node.hpp"
#include "ECS/World.hpp"

RenderSystem::RenderSystem(World& world, RenderWindow& window)
	: System(world)
	, m_window(window)
{
}

void RenderSystem::update(double)
{
	auto tilemap_view = m_world.view<const Node, TileMap>();
	tilemap_view.each(
		[this](const Node&, TileMap& tilemap)
		{
			tilemap.draw(m_window);
		}
	);

	auto sprite_view = m_world.view<const Node, Sprite>();
	sprite_view.each(
		[this](const Node& node, Sprite& sprite)
		{
			sprite.set_position(node.get_position());
			sprite.set_size(node.get_size().as<unsigned>());
			m_window.draw(sprite.get_handle());
		}
	);
}
