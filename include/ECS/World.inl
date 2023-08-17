#include <type_traits>
#include "World.hpp"

template<typename T, typename ...Args>
inline T& World::add_system(Args&& ...args)
{
	static_assert(std::is_base_of<System, T>());
	std::unique_ptr<T> item_ptr = std::make_unique<T>(*this, std::forward<Args>(args)...);
	T& item_ref = *item_ptr;

	m_systems.emplace_back(std::move(item_ptr));

	return item_ref;
}

template<typename ...Types>
inline entt::view< entt::get_t<Types...>> World::view()
{
	return m_registry.view<Types...>();
}
