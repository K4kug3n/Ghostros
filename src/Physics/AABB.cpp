#include "Physics/AABB.hpp"

#include "Maths/Utils.hpp"

#include <utility>
#include <algorithm>
#include <cassert>

AABB::AABB(Vector2f position, Vector2f half)
	: position(std::move(position))
	, half(std::move(half))
{}

std::optional<Hit> AABB::intersect_AABB(const AABB& box) const
{
	const float dx = box.position.x - position.x;
	const float px = (box.half.x + half.x) - abs(dx);
	if (px <= 0) {
		return std::nullopt;
	}

	const float dy = box.position.y - position.y;
	const float py = (box.half.y + half.y) - abs(dy);
	if (py <= 0) {
		return std::nullopt;
	}

	Hit hit{};
	if (px < py) {
		const float sx = (dx > 0) ? 1.f : -1.f;
		hit.delta.x = px * sx;
		hit.normal.x = sx;
		hit.pos.x = position.x + (half.x * sx);
		hit.pos.y = box.position.y;
	}
	else {
		const float sy = (dy > 0) ? 1.f : -1.f;
		hit.delta.y = py * sy;
		hit.normal.y = sy;
		hit.pos.x = box.position.x;
		hit.pos.y = position.y + (half.y * sy);
	}

	return hit;
}

Sweep AABB::sweep_intersection(const AABB& box, const Vector2f& movement) const
{
	constexpr float eps = 0.01f;

	Sweep sweep{};
	if (movement.x == 0 && movement.y == 0)
	{
		sweep.pos.x = box.position.x;
		sweep.pos.y = box.position.y;
		sweep.hit = intersect_AABB(box);
		sweep.time = sweep.hit ? (sweep.hit.value().time = 0) : 1;
		return sweep;
	}

	sweep.hit = intersect_segment(box.position, movement, box.half.x, box.half.y);
	if (sweep.hit) {
		Hit& hit = sweep.hit.value();
		sweep.time = std::clamp(hit.time - eps, 0.f, 1.f);
		sweep.pos.x = box.position.x + movement.x * sweep.time;
		sweep.pos.y = box.position.y + movement.y * sweep.time;
		Vector2f direction = movement;
		direction.normalize();
		hit.pos.x = std::clamp(
			hit.pos.x + direction.x * box.half.x,
			position.x - half.x, position.x + half.x
		);
		hit.pos.y = std::clamp(
			hit.pos.y + direction.y * box.half.y,
			position.y - half.y, position.y + half.y
		);
	}
	else {
		sweep.pos.x = box.position.x + movement.x;
		sweep.pos.y = box.position.y + movement.y;
		sweep.time = 1.f;
	}

	return sweep;
}

std::optional<Hit> AABB::intersect_segment(const Vector2f& pos, const Vector2f& delta, float pad_x, float pad_y) const
{
	const float scale_x = 1.f / delta.x;
	const float scale_y = 1.f / delta.y;
	const float sign_x = sign(scale_x);
	const float sign_y = sign(scale_y);
	const float near_time_x = (position.x - sign_x * (half.x + pad_x) - pos.x) * scale_x;
	const float near_time_y = (position.y - sign_y * (half.y + pad_y) - pos.y) * scale_y;
	const float far_time_x = (position.x + sign_x * (half.x + pad_x) - pos.x) * scale_x;
	const float far_time_y = (position.y + sign_y * (half.y + pad_y) - pos.y) * scale_y;
	
	if (near_time_x > far_time_y || near_time_y > far_time_x)
	{
		return std::nullopt;
	}

	const float near_time = near_time_x > near_time_y ? near_time_x : near_time_y;
	const float far_time = far_time_x < far_time_y ? far_time_x : far_time_y;

	if (near_time >= 1.f || far_time <= 0.f)
	{
		return std::nullopt;
	}

	Hit hit{};
	hit.time = std::clamp(near_time, 0.f, 1.f);
	if (near_time_x > near_time_y) {
		hit.normal.x = -sign_x;
		hit.normal.y = 0.f;
	}
	else {
		hit.normal.x = 0.f;
		hit.normal.y = -sign_y;
	}
	hit.delta.x = (1.f - hit.time) * -delta.x;
	hit.delta.y = (1.f - hit.time) * -delta.y;
	hit.pos.x = pos.x + delta.x * hit.time;
	hit.pos.y = pos.y + delta.y * hit.time;

	return hit;
}

bool AABB::is_intersecting(const AABB& box) const
{
	Vector2f diff = position - box.position;
	return (abs(diff.x) < (half.x + box.half.x)) && (abs(diff.y) < (half.y + box.half.y));
}
