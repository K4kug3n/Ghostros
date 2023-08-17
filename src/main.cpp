#include <iostream>

#include "Window/InputHandler.hpp"
#include "Window/Systems/InputSystems.hpp"
#include "Window/Components/Input.hpp"

#include "Graphics/RenderWindow.hpp"
#include "Graphics/Scene.hpp"
#include "Graphics/TextureCache.hpp"
#include "Graphics/Systems/RenderSystem.hpp"
#include "Graphics/Components/Camera.hpp"
#include "Graphics/Components/AnimatedSprite.hpp"
#include "Graphics/Components/Tilemap.hpp"

#include "ECS/World.hpp"
#include "ECS/EntityHandler.hpp"
#include "ECS/Components/Node.hpp"
#include "ECS/Components/Sprite.hpp"
#include "ECS/Components/State.hpp"
#include "ECS/Components/CollisionCallback.hpp"
#include "ECS/Systems/CollisionTrigger.hpp"
#include "ECS/Systems/PlayerSystem.hpp"

#include "Physics/Systems/PhysicsSpace.hpp"
#include "Physics/Components/RigidBody.hpp"
#include "Physics/Components/StaticBody.hpp"
#include "Physics/Components/Collision.hpp"

int main()
{
	Scene game_scene;

	World& world = game_scene.add_item<World>();
	PhysicsSpace& space = world.add_system<PhysicsSpace>();
	space.set_gravity({ 0.f, 98.1f });

	world.add_system<RenderSystem>();
	world.add_system<CollisionTrigger>();
	EntityHandler player = world.create();

	TextureCache texture_cache;

	TextureHandle player_texture = texture_cache.get("sprites/ghost-1.png");
	AnimatedSprite& ghost_sprite = player.add_component<AnimatedSprite>();
	ghost_sprite.add_animation("idle", std::move(player_texture), 1, 3, 3.f);
	ghost_sprite.play("idle");

	player.add_component<Node>(Vector3f{ 96.f, 96.f, 0.f }, Vector2f{ 27.f, 29.f });
	player.add_component<RigidBody>();
	player.add_component<Input>(Input::NONE);
	player.add_component<State>(State::IDLE);

	EntityHandler tilemap = world.create();
	tilemap.add_component<TileMap>(TileMap::LoadFromFile("stage_1.json"));
	tilemap.add_component<Node>(Vector3f{ 0.f, 0.f, 0.f }, Vector2{ 0.f, 0.f });

	EntityHandler win_trigger = world.create();
	win_trigger.add_component<Node>(Vector3f{ 1724.f, 576.f, 0.f }, Vector2f{ 69.f, 288.f });
	win_trigger.add_flag<StaticBody>();
	TextureHandle flag_texture = texture_cache.get("sprites/flag.png");
	Sprite& flag_sprite = win_trigger.add_component<Sprite>(flag_texture);
	flag_sprite.set_texture_rect({ 0, 0 }, { 23, 96 });
	win_trigger.add_component<CollisionCallback>(
		[flag_texture](const EntityHandler& self, const EntityHandler&, const Vector2f&)
		{ 
			self.remove<StaticBody>();
			self.remove<Collision>();
			self.remove<Sprite>();

			AnimatedSprite& sprite = self.add_component<AnimatedSprite>();
			sprite.add_animation("up", std::move(flag_texture), 1, 5, 1.f);
			sprite.play("up");
		}
	);
	
	RenderWindow window{ 640, 480, "NotSureYet" };
	Camera& camera = player.add_component<Camera>(0, 0, window.get_size().x, window.get_size().y);

	InputHandler input_handler;
	input_handler.register_action("quit", Action{ InputEvent::Window::Closed });
	input_handler.register_action("resize", Action{ InputEvent::Window::Resized });

	input_handler.register_action("right", Action{ InputEvent::Keyboard::D });
	input_handler.register_action("left", Action{ InputEvent::Keyboard::Q });
	input_handler.register_action("up", Action{ InputEvent::Keyboard::Z });
	input_handler.register_action("down", Action{ InputEvent::Keyboard::S });

	world.add_system<InputSystem>(input_handler);
	world.add_system<PlayerSystem>();

	while (window.is_open())
	{
		input_handler.update(window);

		if (input_handler.is_active("quit"))
		{
			window.close();
		}
		if (input_handler.is_active("resize"))
		{
			camera.set_size(window.get_size());
		}

		window.clear();
		game_scene.update(window, input_handler);
		window.display();
	}

	return 0;
}