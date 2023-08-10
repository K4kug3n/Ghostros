#include <iostream>

#include "Window/InputHandler.hpp"

#include "Graphics/RenderWindow.hpp"
#include "Graphics/Scene.hpp"
#include "Graphics/Systems/RenderSystem.hpp"
#include "Graphics/Components/Camera.hpp"
#include "Graphics/Components/AnimatedSprite.hpp"
#include "Graphics/Components/Tilemap.hpp"

#include "ECS/World.hpp"
#include "ECS/EntityHandler.hpp"
#include "ECS/Components/Node.hpp"
#include "ECS/Components/Sprite.hpp"
#include "ECS/Components/CollisionCallback.hpp"
#include "ECS/Systems/CollisionTrigger.hpp"

#include "Physics/Systems/PhysicsSpace.hpp"
#include "Physics/Components/RigidBody.hpp"

int main()
{
	Scene game_scene;

	World& world = game_scene.add_item<World>();
	PhysicsSpace& space = world.add_system<PhysicsSpace>();
	space.set_gravity({ 0.f, 98.1f });

	world.add_system<RenderSystem>();
	world.add_system<CollisionTrigger>();
	EntityHandler player = world.create();

	Texture texture{ "sprites/ghost-1.png" };
	AnimatedSprite& ghost_sprite = player.add_component<AnimatedSprite>();
	ghost_sprite.add_animation("idle", std::move(texture), 1, 3, 3.f);
	ghost_sprite.play("idle");

	player.add_component<Node>(Vector3f{ 96.f, 96.f, 0.f });
	RigidBody& player_body = player.add_component<RigidBody>(1.f, Vector2f{ 27.f, 29.f });

	EntityHandler tilemap = world.create();
	tilemap.add_component<TileMap>(TileMap::LoadFromFile("stage_1.json"));
	tilemap.add_component<Node>(Vector3f{ 0.f, 0.f, 0.f });

	EntityHandler win_trigger = world.create();
	win_trigger.add_component<Node>(Vector3f{ 500.f, 740.f, 0.f });
	win_trigger.add_component<RigidBody>(1.f, Vector2f{ 33.f, 30.f });
	win_trigger.add_component<CollisionCallback>([](const EntityHandler&, const EntityHandler&, const Vector2f&) { std::cout << "Touched" << std::endl; });
	Texture heart_texture{ "sprites/hearth.png" };
	win_trigger.add_component<Sprite>(std::move(heart_texture));

	RenderWindow window{ 640, 480, "NotSureYet" };
	Camera& camera = player.add_component<Camera>(0, 0, window.get_size().x, window.get_size().y);

	InputHandler input_handler;
	input_handler.register_action("quit", Action{ Input::Window::Closed });
	input_handler.register_action("resize", Action{ Input::Window::Resized });

	input_handler.register_action("right", Action{ Input::Keyboard::D });
	input_handler.register_action("left", Action{ Input::Keyboard::Q });
	input_handler.register_action("up", Action{ Input::Keyboard::Z });
	input_handler.register_action("down", Action{ Input::Keyboard::S });

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
		if (input_handler.is_active("up"))
		{
			player_body.jump = true;
		}
		if (input_handler.is_active("down"))
		{
			player_body.velocity.y += 10.f;
		}
		if (input_handler.is_active("left"))
		{
			player_body.velocity.x -= 10.f;
		}
		if (input_handler.is_active("right"))
		{
			player_body.velocity.x += 10.f;
		}

		window.clear();
		game_scene.update(window, input_handler);
		window.display();
	}

	return 0;
}