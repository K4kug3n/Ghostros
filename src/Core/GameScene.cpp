#include "Core/GameScene.hpp"

#include "Window/Systems/InputSystems.hpp"
#include "Window/Components/Input.hpp"

#include "Physics/Systems/PhysicsSpace.hpp"
#include "Physics/Components/StaticBody.hpp"
#include "Physics/Components/RigidBody.hpp"
#include "Physics/Components/Collision.hpp"

#include "ECS/Systems/CollisionTrigger.hpp"
#include "ECS/Systems/PlayerSystem.hpp"
#include "ECS/Components/Node.hpp"
#include "ECS/Components/State.hpp"
#include "ECS/Components/CollisionCallback.hpp"
#include "ECS/EntityHandler.hpp"

#include "Graphics/Systems/RenderSystem.hpp"
#include "Graphics/Systems/CameraSystem.hpp"
#include "Graphics/Systems/AnimationSystem.hpp"
#include "Graphics/Systems/StateAnimationSystem.hpp"
#include "Graphics/Components/StateAnimation.hpp"
#include "Graphics/Components/Sprite.hpp"
#include "Graphics/Components/TileMap.hpp"
#include "Graphics/Components/Camera.hpp"
#include "Graphics/TextureCache.hpp"

GameScene::GameScene(RenderWindow& window, InputHandler& input_handler)
	: m_window(window)
	, m_input_handler(input_handler)
{
}

void GameScene::load()
{
	PhysicsSpace& space = world.add_system<PhysicsSpace>();
	space.set_gravity({ 0.f, 98.1f });

	world.add_system<CollisionTrigger>();
	world.add_system<AnimationSystem>();
	world.add_system<StateAnimationSystem>();
	world.add_system<PlayerSystem>();

	EntityHandler player = world.create();

	TextureCache texture_cache;

	StateAnimation& state_animation = player.add_component<StateAnimation>();
	TextureHandle right_texture = texture_cache.get("sprites/right_ghost.png");
	state_animation.add_animation(State::RUN_RIGHT, { right_texture->get_size(), Vector2u{ 3u, 1u }, 3.f, AnimationRepetition::REPEAT }, right_texture);

	TextureHandle idle_texture = texture_cache.get("sprites/idle_ghost.png");
	state_animation.add_animation(State::IDLE, { idle_texture->get_size(), Vector2u{ 3u, 1u }, 3.f, AnimationRepetition::REPEAT }, idle_texture);

	TextureHandle left_texture = texture_cache.get("sprites/left_ghost.png");
	state_animation.add_animation(State::RUN_LEFT, { left_texture->get_size(), Vector2u{ 3u, 1u }, 3.f, AnimationRepetition::REPEAT }, left_texture);
	player.add_component<Sprite>(std::move(left_texture));

	player.add_component<Node>(Vector3f{ 96.f, 96.f, 0.f }, Vector2f{ 27.f, 29.f });
	player.add_component<RigidBody>();
	player.add_component<Input>(Input::NONE);
	player.add_component<State>(State::IDLE);
	player.add_component<Camera>();

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
		[flag_texture](const EntityHandler& self, const EntityHandler& other, const Vector2f&)
		{
			other.remove<Input>();
			other.get<State>() = State::IDLE;

			self.remove<StaticBody>();
			self.remove<Collision>();

			self.add_component<Animation>(flag_texture->get_size(), Vector2u{ 5u, 1u }, 1.f);
		}
	);

	world.add_system<RenderSystem>(m_window);
	world.add_system<CameraSystem>(m_window);
	world.add_system<InputSystem>(m_input_handler);
}

void GameScene::unload()
{
}

void GameScene::update()
{
	const double elapsed_time = m_clock.get_elapsed_seconds();
	world.update(elapsed_time);
}
