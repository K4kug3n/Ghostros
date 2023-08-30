#ifndef CORE_SCENE_HPP
#define CORE_SCENE_HPP

#include "Utils/Clock.hpp"

class Scene
{
public:
	Scene() = default;
	Scene(const Scene&) = delete;
	Scene(Scene&&) = default;
	virtual ~Scene();

	virtual void load() = 0;
	virtual void unload() = 0;
	virtual void update() = 0;

	Scene& operator=(const Scene&) = delete;
	Scene& operator=(Scene&&) = default;

protected:
	Clock m_clock;
};

#endif


