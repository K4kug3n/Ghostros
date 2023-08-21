#include "EntityHandler.hpp"
template<typename T, typename ...Args>
inline T& EntityHandler::add_component(Args ...args) const
{
	return m_world->get_registry().emplace<T>(m_entity, std::forward<Args>(args)...);
}

template<typename T, typename ...Args>
inline void EntityHandler::add_flag(Args ...args) const
{
	m_world->get_registry().emplace<T>(m_entity, std::forward<Args>(args)...);
}

template<typename T, typename ...Args>
inline T& EntityHandler::add_or_replace_component(Args ...args) const
{
	return m_world->get_registry().emplace_or_replace<T>(m_entity, std::forward<Args>(args)...);
}

template<typename T>
inline T& EntityHandler::get() const
{
	return m_world->get_registry().get<T>(m_entity);
}

template<typename T>
inline void EntityHandler::remove() const
{
	m_world->remove<T>(m_entity);
}
