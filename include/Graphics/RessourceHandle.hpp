#ifndef GRAPHICS_RESSOURCEHANDLE_HPP
#define GRAPHICS_RESSOURCEHANDLE_HPP

#include <memory>

template <typename T>
class RessourceHandle
{
public:
	RessourceHandle() = delete;
	RessourceHandle(std::shared_ptr<T> handle);
	RessourceHandle(const RessourceHandle&) = default;
	RessourceHandle(RessourceHandle&&) = default;
	~RessourceHandle() = default;

	T* operator->() const;

	RessourceHandle& operator=(const RessourceHandle&) = default;
	RessourceHandle& operator=(RessourceHandle&&) = default;

private:
	std::shared_ptr<T> m_handle;
};

#include "Graphics/RessourceHandle.inl"

#endif