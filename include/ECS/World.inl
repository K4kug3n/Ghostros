#include <type_traits>

template<typename T, typename ...Args>
inline void World::add_system(Args ...args)
{
	static_assert(std::is_base_of<System, T>);
	m_systems.emplace_back(std::make_unique<T>(std::forward<Args>(args)...));
}