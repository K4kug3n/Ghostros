#ifndef PHYSICS_COMPONENTS_STATICBODY_HPP
#define PHYSICS_COMPONENTS_STATICBODY_HPP

#include "Maths/Vector2.hpp"

class StaticBody
{
public:
	StaticBody() = default;
	StaticBody(StaticBody&&) = default;
	StaticBody(const StaticBody&) = delete;
	~StaticBody() = default;

	StaticBody& operator=(StaticBody&&) = default;
	StaticBody& operator=(const StaticBody&) = delete;
};

#endif