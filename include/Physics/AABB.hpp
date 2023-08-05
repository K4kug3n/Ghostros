#ifndef PHYSICS_AABB_HPP
#define PHYSICS_AABB_HPP

#include <optional>

#include "Maths/Vector2.hpp"

#include "Physics/Sweep.hpp"
#include "Physics/Hit.hpp"

class AABB
{
public:
	AABB() = delete;
	AABB(Vector2f position, Vector2f half);
	AABB(AABB&&) = default;
	AABB(const AABB&) = delete;
	~AABB() = default;

	std::optional<Hit> intersect_AABB(const AABB& box) const;
	std::optional<Hit> intersect_segment(const Vector2f& pos, const Vector2f& delta, float pad_x, float pad_y) const;
	bool is_intersecting(const AABB& box) const;
	Sweep sweep_intersection(const AABB& box, const Vector2f& movement) const;

	AABB& operator=(AABB&&) = default;
	AABB& operator=(const AABB&) = delete;

	Vector2f position;
	Vector2f half;
};

#endif