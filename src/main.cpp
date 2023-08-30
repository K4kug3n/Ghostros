#include <iostream>

#include "Core/GameScene.hpp"

#include "Window/InputHandler.hpp"
#include "Window/Systems/InputSystems.hpp"
#include "Window/Components/Input.hpp"

#include "Graphics/RenderWindow.hpp"
#include "Graphics/TextureCache.hpp"
#include "Graphics/Systems/AnimationSystem.hpp"
#include "Graphics/Systems/StateAnimationSystem.hpp"
#include "Graphics/Systems/RenderSystem.hpp"
#include "Graphics/Systems/CameraSystem.hpp"
#include "Graphics/Components/Camera.hpp"
#include "Graphics/Components/Animation.hpp"
#include "Graphics/Components/Tilemap.hpp"
#include "Graphics/Components/StateAnimation.hpp"
#include "Graphics/Components/Sprite.hpp"

#include "ECS/World.hpp"
#include "ECS/EntityHandler.hpp"
#include "ECS/Components/Node.hpp"
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
	GameScene game_scene;
	game_scene.load();

	World& world = game_scene.world;
	
	RenderWindow window{ 640, 480, "Ghostros" };
	world.add_system<RenderSystem>(window);
	world.add_system<CameraSystem>(window);

	InputHandler input_handler;
	input_handler.register_action("quit", Action{ InputEvent::Window::Closed });

	input_handler.register_action("right", Action{ InputEvent::Keyboard::D });
	input_handler.register_action("left", Action{ InputEvent::Keyboard::Q });
	input_handler.register_action("up", Action{ InputEvent::Keyboard::Z });
	input_handler.register_action("down", Action{ InputEvent::Keyboard::S });

	world.add_system<InputSystem>(input_handler);

	while (window.is_open())
	{
		input_handler.update(window);

		if (input_handler.is_active("quit"))
		{
			window.close();
		}

		window.clear();
		game_scene.update();
		window.display();
	}

	return 0;
}