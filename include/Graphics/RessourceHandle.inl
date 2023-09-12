#include "RessourceHandle.hpp"
template<typename T>
inline RessourceHandle<T>::RessourceHandle(std::shared_ptr<T> handle)
	: m_handle(std::move(handle))
{
}

template<typename T>
inline T* RessourceHandle<T>::operator->() const
{
	return m_handle.get();
}