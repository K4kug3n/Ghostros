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

#include "Physics/Systems/PhysicsSpace.hpp"
#include "Physics/Components/RigidBody.hpp"

int main()
{
	Scene game_scene;

	World& world = game_scene.add_item<World>();
	PhysicsSpace& space = world.add_system<PhysicsSpace>();
	space.set_gravity({ 0.f, 9.81f });

	world.add_system<RenderSystem>();
	EntityHandler player = world.create();

	Texture texture{ "sprites/ghost-1.png" };
	AnimatedSprite& ghost_sprite = player.add_component<AnimatedSprite>();
	ghost_sprite.add_animation("idle", std::move(texture), 1, 3, 3.f);
	ghost_sprite.play("idle");

	player.add_component<Node>(Vector3f{ 10.f, 0.f, 0.f });
	RigidBody& player_body = player.add_component<RigidBody>(1.f);
	player_body.force.x += 10.f;

	EntityHandler tilemap = world.create();
	tilemap.add_component<TileMap>(TileMap::LoadFromFile("stage_1.json"));
	tilemap.add_component<Node>(Vector3f{ 0.f, 0.f, 0.f });

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
			//camera.move({ 0.f, -5.f });
		}
		if (input_handler.is_active("down"))
		{
			//camera.move({ 0.f, 5.f });
		}
		if (input_handler.is_active("left"))
		{
			//camera.move({ -5.f, 0.f });
		}
		if (input_handler.is_active("right"))
		{
			//camera.move({ 5.f, 0.f });
		}

		window.clear();
		game_scene.update(window, input_handler);
		window.display();
	}

	return 0;
}