#include <iostream>

#include "Graphics/Tilemap.hpp"
#include "Graphics/RenderWindow.hpp"
#include "Graphics/Camera.hpp"
#include "Window/InputHandler.hpp"

#include "Graphics/Scene.hpp"
#include "Graphics/Systems/RenderSystem.hpp"

#include "ECS/World.hpp"
#include "ECS/EntityHandler.hpp"
#include "ECS/Components/Sprite.hpp"
#include "ECS/Components/Node.hpp"

int main()
{
	Scene game_scene;
	game_scene.add_item<TileMap>(TileMap::LoadFromFile("stage_1.json"));

	World& world = game_scene.add_item<World>();
	world.add_system<RenderSystem>();
	EntityHandler player = world.create();

	Texture texture{ "sprites/ghost-1.png" };
	player.add_compoment<Sprite>(std::move(texture));
	player.add_compoment<Node>(Vector3f{ 10.f, 0.f, 0.f });

	RenderWindow window{ 640, 480, "NotSureYet" };

	InputHandler input_handler;
	input_handler.register_action("quit", Action{ Input::Window::Closed });
	input_handler.register_action("resize", Action{ Input::Window::Resized });

	input_handler.register_action("right", Action{ Input::Keyboard::D });
	input_handler.register_action("left", Action{ Input::Keyboard::Q });
	input_handler.register_action("up", Action{ Input::Keyboard::Z });
	input_handler.register_action("down", Action{ Input::Keyboard::S });

	Camera camera{ 0, 0, window.get_size().x, window.get_size().y };
	window.set_camera(camera);

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
			window.set_camera(camera);
		}
		if (input_handler.is_active("up"))
		{
			camera.move({ 0.f, -5.f });
			window.set_camera(camera);
		}
		if (input_handler.is_active("down"))
		{
			camera.move({ 0.f, 5.f });
			window.set_camera(camera);
		}
		if (input_handler.is_active("left"))
		{
			camera.move({ -5.f, 0.f });
			window.set_camera(camera);
		}
		if (input_handler.is_active("right"))
		{
			camera.move({ 5.f, 0.f });
			window.set_camera(camera);
		}

		window.clear();
		game_scene.update(window, input_handler);
		window.display();
	}

	return 0;
}