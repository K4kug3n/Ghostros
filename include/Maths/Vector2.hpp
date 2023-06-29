#ifndef MATHS_VECTOR2_HPP
#define MATHS_VECTOR2_HPP

template <typename T>
class Vector2 
{
public:
	Vector2() = delete;
	Vector2(T x, T y);
	Vector2(const Vector2&) = default;
	Vector2(Vector2&&) = default;
	~Vector2() = default;

	T x, y;

	Vector2& operator=(const Vector2&) = default;
	Vector2& operator=(Vector2&&) = default;
};

using Vector2f = Vector2<float>;
using Vector2i = Vector2<int>;

#include "Vector2.inl"

#endif