template<typename T>
inline RessourceHandle<T> RessourceCache<T>::get(const std::filesystem::path& filepath)
{
	std::string key = std::filesystem::absolute(filepath).generic_string();
	if (m_cache.count(key) != 0)
	{
		std::weak_ptr<Texture>& weak_ressource = m_cache[key];
		if (auto ressource = weak_ressource.lock())
		{
			return RessourceHandle<Texture>{ std::move(ressource) };
		}
	}

	std::shared_ptr<T> ressrouce = std::make_shared<T>(filepath);
	m_cache[key] = ressrouce;

	return RessourceHandle<Texture>{ std::move(ressrouce) };
}