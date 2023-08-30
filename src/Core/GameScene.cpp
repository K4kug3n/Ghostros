#include "Core/GameScene.hpp"

void GameScene::load()
{
}

void GameScene::unload()
{
}

void GameScene::update()
{
	const double elapsed_time = m_clock.get_elapsed_seconds();
	world.update(elapsed_time);
}
