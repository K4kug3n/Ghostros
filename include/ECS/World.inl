#include <type_traits>
#include "World.hpp"

template<typename T, typename ...Args>
inline void World::add_system(Args ...args)
{
	static_assert(std::is_base_of<System, T>());
	m_systems.emplace_back(std::make_unique<T>(*this, std::forward<Args>(args)...));
}

template<typename ...Types>
inline entt::view< entt::get_t<Types...>> World::view()
{
	return m_registry.view<Types...>();
}
