#include "Physics/Systems/PhysicsSpace.hpp"

#include <utility>

#include "ECS/World.hpp"
#include "ECS/Components/Node.hpp"

#include "Physics/Components/RigidBody.hpp"

#include "Graphics/Components/TileMap.hpp"

PhysicsSpace::PhysicsSpace(World& world)
	: System(world)
	, m_gravity(0.f, 0.f)
{
}

void PhysicsSpace::update(RenderWindow&, InputHandler&, double delta_time)
{
	step(static_cast<float>(delta_time));
}

void PhysicsSpace::set_gravity(Vector2f gravity)
{
	m_gravity = std::move(gravity);
}

void PhysicsSpace::step(float dt)
{
	auto body_view = m_world.view<Node, RigidBody>();
	auto tilemap_view = m_world.view<TileMap>();

	for (auto [_, node, body] : body_view.each())
	{
		if (body.jump && body.on_ground)
		{
			body.velocity.y = -100.f;
			body.jump = false;
			body.on_ground = false;
		}
		else if (body.jump)
		{
			body.jump = false;
		}

		body.velocity.x = std::min(body.velocity.x, 100.f);
		
		body.velocity += m_gravity * dt;
		
		Vector2f movement = body.velocity * dt;
		Vector3f new_pos = Vector3f{ movement.x, movement.y, 0.f } + node.get_position();

		for (auto [_, tilemap] : tilemap_view.each())
		{
			resolve_tilemap_collision(new_pos, node.get_position(), body, tilemap);
		}

		node.set_position(new_pos);
	}
}

void PhysicsSpace::resolve_tilemap_collision(Vector3f& new_pos, const Vector3f& old_pos, RigidBody& body, const TileMap& tilemap)
{
	const AABB body_AABB{ { old_pos.x + body.size.x / 2.f, old_pos.y + body.size.y / 2.f }, body.size / 2.f };
	const Vector3f movement = new_pos - old_pos;

	const Vector2i tilemap_pos_tl = tilemap.world_to_map({ new_pos.x, new_pos.y });
	const uint8_t id_tl = tilemap.get_cell_id(tilemap_pos_tl.x, tilemap_pos_tl.y);
	const TileProperties& properties_tl = tilemap.get_tile_set().get_properties(id_tl);

	const Vector2i tilemap_pos_tr = tilemap.world_to_map({ new_pos.x + body.size.x, new_pos.y });
	const uint8_t id_tr = tilemap.get_cell_id(tilemap_pos_tr.x, tilemap_pos_tr.y);
	const TileProperties& properties_tr = tilemap.get_tile_set().get_properties(id_tr);

	const Vector2i tilemap_pos_bl = tilemap.world_to_map({ new_pos.x, new_pos.y + body.size.y });
	const uint8_t id_bl = tilemap.get_cell_id(tilemap_pos_bl.x, tilemap_pos_bl.y);
	const TileProperties& properties_bl = tilemap.get_tile_set().get_properties(id_bl);

	const Vector2i tilemap_pos_br = tilemap.world_to_map({ new_pos.x + body.size.x, new_pos.y + body.size.y });
	const uint8_t id_br = tilemap.get_cell_id(tilemap_pos_br.x, tilemap_pos_br.y);
	const TileProperties& properties_br = tilemap.get_tile_set().get_properties(id_br);

	std::vector<AABB> colliders{};
	if (properties_tl.collide)
	{
		colliders.emplace_back(tilemap.get_AABB(tilemap_pos_tl.x, tilemap_pos_tl.y));
	}

	if (properties_tr.collide)
	{
		colliders.emplace_back(tilemap.get_AABB(tilemap_pos_tr.x, tilemap_pos_tr.y));
	}

	if (properties_bl.collide)
	{
		colliders.emplace_back(tilemap.get_AABB(tilemap_pos_bl.x, tilemap_pos_bl.y));
	}

	if (properties_br.collide)
	{
		colliders.emplace_back(tilemap.get_AABB(tilemap_pos_br.x, tilemap_pos_br.y));
	}

	Sweep nearest{};
	nearest.time = 1;
	nearest.pos.x = (old_pos.x + body.size.x / 2) + movement.x;
	nearest.pos.y = (old_pos.y + body.size.y / 2) + movement.y;
	for (size_t i = 0; i < colliders.size(); ++i)
	{
		Sweep sweep = colliders[i].sweep_intersection(body_AABB, { movement.x, movement.y });
		if (sweep.time < nearest.time) {
			nearest = std::move(sweep);
		}
	}
	
	new_pos = { nearest.pos.x - body_AABB.half.x, nearest.pos.y - body_AABB.half.y, new_pos.z };

	if (nearest.time != 1)
	{
		if (nearest.hit.value().normal.x != 0)
		{
			body.velocity.x = 0.f;
		}
		else if (nearest.hit.value().normal.y != 0)
		{
			body.velocity.y = 0.f;
		}

		if (nearest.hit.value().normal.y == -1)
		{
			body.on_ground = true;
		}
	}
}
