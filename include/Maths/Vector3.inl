template<typename T>
inline Vector3<T>::Vector3(T x, T y, T z)
	: x(x)
	, y(y)
	, z(z)
{}

template<typename T>
inline T Vector3<T>::length() const
{
	return static_cast<T>(std::sqrt(x * x + y * y + z * z));
}

template<typename T>
inline void Vector3<T>::normalize()
{
	const T l = length();
	x /= l;
	y /= l;
	z /= l;
}

template<typename T>
inline Vector3<T>& Vector3<T>::operator+=(const Vector3<T>& other)
{
	*this = *this + other;
	return *this;
}

template<typename T>
inline Vector3<T>& Vector3<T>::operator-=(const Vector3<T>& other)
{
	*this = *this - other;
	return *this;
}

template <typename T>
inline Vector3<T> operator+(const Vector3<T>& lhs, const Vector3<T>& rhs)
{
	return Vector3<T>{ lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z };
}

template <typename T>
inline Vector3<T> operator-(const Vector3<T>& lhs, const Vector3<T>& rhs)
{
	return Vector3<T>{ lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z };
}