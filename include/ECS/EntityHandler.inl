template<typename T, typename ...Args>
inline T& EntityHandler::add_compoment(Args ...args)
{
	return m_world.get_registry().emplace<T>(m_entity, std::forward<Args>(args)...);
}