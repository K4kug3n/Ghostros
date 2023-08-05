#ifndef PHYSICS_HIT_HPP
#define PHYSICS_HIT_HPP

#include "Maths/Vector2.hpp"

class Hit
{
public:
	Hit();
	Hit(const Hit&) = delete;
	Hit(Hit&&) = default;
	~Hit() = default;

	Hit& operator=(const Hit&) = delete;
	Hit& operator=(Hit&&) = default;

	Vector2f pos;
	Vector2f delta;
	Vector2f normal;
	float time;
};

#endif