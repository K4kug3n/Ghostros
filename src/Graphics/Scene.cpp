#include "Graphics/Scene.hpp"

#include "Graphics/SceneItem.hpp"

Scene::Scene()
	: m_clock()
{}

void Scene::update(RenderWindow& window, InputHandler& input_handler)
{
	const double delta_time = m_clock.get_elapsed_seconds();
	for (auto&& item : m_items)
	{
		item->update(window, input_handler, delta_time);
	}
}