#ifndef MATHS_VECTOR3_HPP
#define MATHS_VECTOR3_HPP

#include "Maths/Vector2.hpp"

template <typename T>
class Vector3
{
public:
	Vector3() = delete;
	Vector3(T x, T y, T z);
	Vector3(const Vector3&) = default;
	Vector3(Vector3&&) = default;
	~Vector3() = default;
	
	template<typename U>
	Vector3<U> as() const;
	T length() const;
	void normalize();

	Vector2<T> xy() const;
	Vector2<T> xz() const;
	Vector2<T> yz() const;

	Vector3& operator+=(const Vector3& other);
	Vector3& operator-=(const Vector3& other);

	Vector3& operator=(const Vector3&) = default;
	Vector3& operator=(Vector3&&) = default;

	T x, y, z;
};

using Vector3f = Vector3<float>;
using Vector3i = Vector3<int>;
using Vector3u = Vector3<unsigned>;

template <typename T>
Vector3<T> operator+(const Vector3<T>& lhs, const Vector3<T>& rhs);

template <typename T>
Vector3<T> operator-(const Vector3<T>& lhs, const Vector3<T>& rhs);

#include "Maths/Vector3.inl"

#endif