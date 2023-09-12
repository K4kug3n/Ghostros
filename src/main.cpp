#include "Core/GameScene.hpp"
#include "Core/MenuScene.hpp"
#include "Core/SceneManager.hpp"

#include "Window/InputHandler.hpp"

#include "Graphics/RenderWindow.hpp"

#include "Widgets/Button.hpp"

int main()
{	
	RenderWindow window{ 640, 480, "Ghostros" };

	InputHandler input_handler;
	input_handler.register_action("quit", Action{ InputEvent::Window::Closed });

	input_handler.register_action("right", Action{ InputEvent::Keyboard::D });
	input_handler.register_action("left", Action{ InputEvent::Keyboard::Q });
	input_handler.register_action("up", Action{ InputEvent::Keyboard::Z });
	input_handler.register_action("down", Action{ InputEvent::Keyboard::S });

	GameScene game_scene{ window, input_handler };
	game_scene.load();

	SceneManager scene_manager;
	
	MenuScene menu_scene{ window, input_handler };
	menu_scene.load();
	menu_scene.get_quit_button().on_click([&window]() { window.close(); });
	menu_scene.get_play_button().on_click([&scene_manager, &game_scene]() { scene_manager.set_current_scene(game_scene); });

	scene_manager.set_current_scene(menu_scene);

	while (window.is_open())
	{
		input_handler.update(window);

		if (input_handler.is_active("quit"))
		{
			window.close();
		}

		window.clear();
		scene_manager.update_scene();
		window.display();
	}

	return 0;
}