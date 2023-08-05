#ifndef PHYSICS_SWEEP_HPP
#define PHYSICS_SWEEP_HPP

#include <optional>

#include "Maths/Vector2.hpp"
#include "Physics/Hit.hpp"

class Sweep
{
public:
	Sweep();
	Sweep(const Sweep&) = delete;
	Sweep(Sweep&&) = default;
	~Sweep() = default;

	Sweep& operator=(const Sweep&) = delete;
	Sweep& operator=(Sweep&&) = default;


	std::optional<Hit> hit;
	Vector2f pos;
	float time;
};

#endif