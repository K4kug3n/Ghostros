#include <iostream>

#include "Tilemap.hpp"
#include "Window/RenderWindow.hpp"
#include "Window/InputHandler.hpp"

int main()
{
	TileMap tilemap = TileMap::LoadFromFile("stage_1.json");

	RenderWindow window{ 640, 480, "NotSureYet" };
	InputHandler input_handler;

	input_handler.register_action("quit", Action{ Input::Window::Closed });

	while (window.is_open())
	{
		input_handler.update(window);

		if (input_handler.is_active("quit")) {
			window.close();
		}

		window.display();
	}

	return 0;
}