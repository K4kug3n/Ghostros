#include "Graphics/Systems/RenderSystem.hpp"

#include "Graphics/RenderWindow.hpp"
#include "Graphics/Components/AnimatedSprite.hpp"

#include "ECS/Components/Node.hpp"
#include "ECS/Components/Sprite.hpp"
#include "ECS/World.hpp"

RenderSystem::RenderSystem(World& world)
	: System(world)
{
}

void RenderSystem::update(RenderWindow& window, InputHandler&, double delta_t)
{
	auto sprite_view = m_world.view<Node, Sprite>();
	sprite_view.each([&window](Node& node, Sprite& sprite)
		{
			sprite.set_position(node.position);
			window.draw(sprite.get_handle());
		}
	);

	auto animated_sprite_view = m_world.view<const Node, AnimatedSprite>();
	animated_sprite_view.each([&window, delta_t](const Node& node, AnimatedSprite& animated_sprite)
		{
			animated_sprite.update(delta_t);
			sf::Sprite& sprite = animated_sprite.get_frame();
			sprite.setPosition({ node.position.x, node.position.y });
			window.draw(sprite);
		}
	);
}
