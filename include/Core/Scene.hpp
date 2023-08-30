#ifndef CORE_SCENE_HPP
#define CORE_SCENE_HPP

#include <vector>
#include <memory>

#include "Utils/Clock.hpp"

class InputHandler;
class RenderWindow;
class SceneItem;

class Scene
{
public:
	Scene();
	Scene(const Scene&) = delete;
	Scene(Scene&&) = default;
	~Scene() = default;

	template<typename T, typename... Args>
	T& add_item(Args... args);
	void update(RenderWindow& window, InputHandler& input_handler);

	Scene& operator=(const Scene&) = delete;
	Scene& operator=(Scene&&) = default;
private:
	Clock m_clock;

	std::vector<std::unique_ptr<SceneItem>> m_items;
};

#include "Core/Scene.inl"

#endif


