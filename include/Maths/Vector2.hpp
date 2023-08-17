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

	template<typename U>
	Vector2<U> as() const;
	T length() const;
	void normalize();

	Vector2& operator+=(const Vector2& other);
	Vector2& operator-=(const Vector2& other);
	Vector2& operator*=(const Vector2& other);

	Vector2& operator=(const Vector2&) = default;
	Vector2& operator=(Vector2&&) = default;

	T x, y;
};

using Vector2f = Vector2<float>;
using Vector2i = Vector2<int>;
using Vector2u = Vector2<unsigned>;

template <typename T>
Vector2<T> operator+(const Vector2<T>& lhs, const Vector2<T>& rhs);

template <typename T>
Vector2<T> operator-(const Vector2<T>& lhs, const Vector2<T>& rhs);

template <typename T>
Vector2<T> operator*(const Vector2<T>& lhs, const Vector2<T>& rhs);

template <typename T>
Vector2<T> operator*(const Vector2<T>& lhs, T coeff);

template <typename T>
Vector2<T> operator*(T coeff, const Vector2<T>& rhs);

template <typename T>
Vector2<T> operator/(const Vector2<T>& lhs, const Vector2<T>& rhs);

template <typename T>
Vector2<T> operator/(const Vector2<T>& lhs, T coeff);

template <typename T>
Vector2<T> operator/(T coeff, const Vector2<T>& rhs);

template<typename T>
bool operator==(const Vector2<T>& lhs, const Vector2<T>& rhs);

template<typename T>
bool operator!=(const Vector2<T>& lhs, const Vector2<T>& rhs);

#include "Maths/Vector2.inl"

#endif