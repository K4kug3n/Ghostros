#include "Core/GameScene.hpp"
#include "Core/MenuScene.hpp"

#include "Window/InputHandler.hpp"

#include "Graphics/RenderWindow.hpp"

int main()
{	
	RenderWindow window{ 640, 480, "Ghostros" };

	InputHandler input_handler;
	input_handler.register_action("quit", Action{ InputEvent::Window::Closed });

	input_handler.register_action("right", Action{ InputEvent::Keyboard::D });
	input_handler.register_action("left", Action{ InputEvent::Keyboard::Q });
	input_handler.register_action("up", Action{ InputEvent::Keyboard::Z });
	input_handler.register_action("down", Action{ InputEvent::Keyboard::S });

	//GameScene game_scene{ window, input_handler };
	//game_scene.load();

	MenuScene menu_scene{ window, input_handler };
	menu_scene.load();

	while (window.is_open())
	{
		input_handler.update(window);

		if (input_handler.is_active("quit"))
		{
			window.close();
		}

		window.clear();
		//game_scene.update();
		menu_scene.update();
		window.display();
	}

	return 0;
}