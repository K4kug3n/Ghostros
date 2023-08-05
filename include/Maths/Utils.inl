template<typename T>
inline T sign(T val)
{
	if (val > 0.f)
	{
		return static_cast<T>(1.f);
	}
	if (val < 0.f)
	{
		return static_cast<T>(-1.f);
	}

	return static_cast<T>(0.f);
}