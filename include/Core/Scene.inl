#include "Core/Scene.hpp"

template<typename T, typename ...Args>
T& Scene::add_item(Args ...args)
{
	static_assert(std::is_base_of<SceneItem, T>());
	std::unique_ptr<T> item_ptr = std::make_unique<T>(std::forward<Args>(args)...);
	T& item_ref = *item_ptr;

	m_items.emplace_back(std::move(item_ptr));

	return item_ref;
}