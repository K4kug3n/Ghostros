#ifndef CORE_SCENEMANAGER_HPP
#define CORE_SCENEMANAGER_HPP

class Scene;

class SceneManager
{
public:
	SceneManager() = default;
	SceneManager(const SceneManager&) = delete;
	SceneManager(SceneManager&& other) noexcept;
	~SceneManager() = default;

	void set_current_scene(Scene& scene);
	void update_scene() const;

	SceneManager& operator=(const SceneManager&) = delete;
	SceneManager& operator=(SceneManager&& other) noexcept;

private:
	Scene* m_current_scene;
};

#endif


