#include "Maths/Vector2.hpp"

#include <cmath>

template<typename T>
inline Vector2<T>::Vector2(T x, T y)
	: x(x)
	, y(y)
{}

template<typename T>
template<typename U>
inline Vector2<U> Vector2<T>::as() const
{
	return Vector2<U>{ static_cast<U>(x), static_cast<U>(y) };
}

template<typename T>
inline T Vector2<T>::length() const
{
	return static_cast<T>(std::sqrt(x * x + y * y));
}

template<typename T>
inline void Vector2<T>::normalize()
{
	const T l = length();
	x /= l;
	y /= l;
}

template<typename T>
inline Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& other)
{
	*this = *this + other;
	return *this;
}

template<typename T>
inline Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& other)
{
	*this = *this - other;
	return *this;
}

template<typename T>
inline Vector2<T>& Vector2<T>::operator*=(const Vector2<T>& other)
{
	*this = *this * other;
	return *this;
}

template <typename T>
inline Vector2<T> operator+(const Vector2<T>& lhs, const Vector2<T>& rhs)
{
	return Vector2<T>{ lhs.x + rhs.x, lhs.y + rhs.y };
}

template <typename T>
inline Vector2<T> operator-(const Vector2<T>& lhs, const Vector2<T>& rhs)
{
	return Vector2<T>{ lhs.x - rhs.x, lhs.y - rhs.y };
}

template<typename T>
inline Vector2<T> operator*(const Vector2<T>& lhs, const Vector2<T>& rhs)
{
	return Vector2<T>{ lhs.x * rhs.x, lhs.y * rhs.y };
}

template <typename T>
inline Vector2<T> operator*(const Vector2<T>& lhs, T coeff)
{
	return Vector2<T>{ lhs.x * coeff, lhs.y * coeff };
}

template <typename T>
inline Vector2<T> operator*(T coeff, const Vector2<T>& rhs)
{
	return rhs * coeff;
}

template<typename T>
inline Vector2<T> operator/(const Vector2<T>& lhs, const Vector2<T>& rhs)
{
	return Vector2<T>{ lhs.x / rhs.x, lhs.y / rhs.y };
}

template <typename T>
Vector2<T> operator/(const Vector2<T>& lhs, T coeff)
{
	return Vector2<T>{ lhs.x / coeff, lhs.y / coeff };
}

template <typename T>
Vector2<T> operator/(T coeff, const Vector2<T>& rhs)
{
	return rhs / coeff;
}

template<typename T>
bool operator==(const Vector2<T>& lhs, const Vector2<T>& rhs)
{
	return (lhs.x == rhs.x) && (lhs.y == rhs.y);
}

template<typename T>
bool operator!=(const Vector2<T>& lhs, const Vector2<T>& rhs)
{
	return !(lhs == rhs);
}