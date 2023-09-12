#include "Core/SceneManager.hpp"

#include <cassert>

#include "Core/Scene.hpp"

SceneManager::SceneManager(SceneManager&& other) noexcept
	: m_current_scene(other.m_current_scene)
{
}

void SceneManager::set_current_scene(Scene& scene)
{
	m_current_scene = &scene;
}

void SceneManager::update_scene() const
{
	assert(m_current_scene != nullptr);
	m_current_scene->update();
}

SceneManager& SceneManager::operator=(SceneManager&& other) noexcept
{
	m_current_scene = other.m_current_scene;
	return *this;
}
