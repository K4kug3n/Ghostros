#ifndef GRAPHICS_RESSOURCECACHE_HPP
#define GRAPHICS_RESSOURCECACHE_HPP

#include <filesystem>
#include <unordered_map>
#include <memory>

#include "Graphics/RessourceHandle.hpp"

template <typename T>
class RessourceCache
{
public:
	RessourceCache() = default;
	RessourceCache(const RessourceCache&) = delete;
	RessourceCache(RessourceCache&&) = default;
	~RessourceCache() = default;

	RessourceHandle<T> get(const std::filesystem::path& filepath);

	RessourceCache& operator=(const RessourceCache&) = delete;
	RessourceCache& operator=(RessourceCache&&) = default;

private:
	std::unordered_map<std::string, std::weak_ptr<T>> m_cache;
};

#include "Graphics/RessourceCache.inl"

#endif