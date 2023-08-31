#ifndef CORE_GAMESCENE_HPP
#define CORE_GAMESCENE_HPP

#include "Core/Scene.hpp"

#include "ECS/World.hpp"

class GameScene : public Scene
{
public:
	GameScene() = delete;
	GameScene(RenderWindow& window, InputHandler& input_handler);
	GameScene(const GameScene&) = delete;
	GameScene(GameScene&&) = default;
	~GameScene() = default;

	void load() override;
	void unload() override;
	void update() override;

	World world;

	GameScene& operator=(const GameScene&) = delete;
	GameScene& operator=(GameScene&&) = default;
private:
	RenderWindow& m_window;
	InputHandler& m_input_handler;
};

#endif


