#include "Physics/Systems/PhysicsSpace.hpp"

#include <utility>

#include "ECS/World.hpp"
#include "ECS/EntityHandler.hpp"
#include "ECS/Components/Node.hpp"

#include "Physics/Components/RigidBody.hpp"
#include "Physics/Components/StaticBody.hpp"
#include "Physics/Components/Collision.hpp"

#include "Graphics/Components/TileMap.hpp"

bool tilemap_collsion(Vector3f& new_pos, const Vector3f& old_pos, const Vector2f& size, RigidBody& body, const TileMap& tilemap)
{
	const AABB body_AABB{ old_pos.xy() + size / 2.f, size / 2.f };
	const Vector3f movement = new_pos - old_pos;

	const Vector2i tilemap_pos_tl = tilemap.world_to_map(new_pos.xy());
	const uint8_t id_tl = tilemap.get_cell_id(tilemap_pos_tl.x, tilemap_pos_tl.y);
	const TileProperties& properties_tl = tilemap.get_tile_set().get_properties(id_tl);

	const Vector2i tilemap_pos_tr = tilemap.world_to_map({ new_pos.x + size.x, new_pos.y });
	const uint8_t id_tr = tilemap.get_cell_id(tilemap_pos_tr.x, tilemap_pos_tr.y);
	const TileProperties& properties_tr = tilemap.get_tile_set().get_properties(id_tr);

	const Vector2i tilemap_pos_bl = tilemap.world_to_map({ new_pos.x, new_pos.y + size.y });
	const uint8_t id_bl = tilemap.get_cell_id(tilemap_pos_bl.x, tilemap_pos_bl.y);
	const TileProperties& properties_bl = tilemap.get_tile_set().get_properties(id_bl);

	const Vector2i tilemap_pos_br = tilemap.world_to_map(new_pos.xy() + size);
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
	nearest.time = 1.f;
	nearest.pos.x = (old_pos.x + size.x / 2.f) + movement.x;
	nearest.pos.y = (old_pos.y + size.y / 2.f) + movement.y;
	for (size_t i = 0; i < colliders.size(); ++i)
	{
		Sweep sweep = colliders[i].sweep_intersection(body_AABB, movement.xy());
		if (sweep.time < nearest.time) {
			nearest = std::move(sweep);
		}
	}

	new_pos = { nearest.pos.x - body_AABB.half.x, nearest.pos.y - body_AABB.half.y, new_pos.z };

	return nearest.time != 1.f;
}

void resolve_tilemap_collision(Vector3f& new_pos, const Vector3f& old_pos, const Vector2f& size, RigidBody& body, const TileMap& tilemap)
{
	const Vector2f movement = new_pos.xy() - old_pos.xy();
	Vector3f partial_pos{ old_pos.x, old_pos.y + movement.y, old_pos.z };

	if (tilemap_collsion(partial_pos, old_pos, size, body, tilemap))
	{
		body.velocity.y = 0.f;
		if (movement.y > 0.f)
		{
			body.on_ground = true;
		}
	}
	
	partial_pos.x += movement.x;
	if (tilemap_collsion(partial_pos, old_pos, size, body, tilemap))
	{
		body.velocity.x = 0.f;
	}

	new_pos = partial_pos;
}

PhysicsSpace::PhysicsSpace(World& world)
	: System(world)
	, m_gravity(0.f, 0.f)
{
}

void PhysicsSpace::update(double delta_time)
{
	step(std::min(static_cast<float>(delta_time), 0.16f));
}

void PhysicsSpace::set_gravity(Vector2f gravity)
{
	m_gravity = std::move(gravity);
}

void PhysicsSpace::step(float dt)
{
	auto body_view = m_world.view<Node, RigidBody>();
	auto tilemap_view = m_world.view<TileMap>();

	for (auto [_, node, body] : body_view.each()) // Move & Map collision
	{
		if (body.jump && body.on_ground)
		{
			body.velocity.y = -120.f;
			body.jump = false;
			body.on_ground = false;
		}
		else if (body.jump)
		{
			body.jump = false;
		}

		body.velocity.x = std::max(std::min(body.velocity.x, 100.f), -100.f);

		body.velocity += m_gravity * dt;

		Vector2f movement = body.velocity * dt;
		Vector3f new_pos = Vector3f{ movement.x, movement.y, 0.f } + node.get_position();

		for (auto [_, tilemap] : tilemap_view.each())
		{
			resolve_tilemap_collision(new_pos, node.get_position(), node.get_size(), body, tilemap);
		}
		 
		node.set_position(new_pos);
	}

	for (auto [id_a, node_a, _] : body_view.each()) // Entity collision
	{
		for (auto [id_b, node_b, _] : body_view.each())
		{
			if (id_a == id_b)
			{
				continue;
			}

			AABB aabb_a{ node_a.get_center().xy(), node_a.get_size() / 2.f };
			AABB aabb_b{ node_b.get_center().xy(), node_b.get_size() / 2.f };

			if (aabb_a.is_intersecting(aabb_b))
			{
				EntityHandler handler_a{ m_world, id_a };
				EntityHandler handler_b{ m_world, id_b };

				handler_a.add_or_replace_component<Collision>(Collision{ handler_b, node_a.get_position().xy() });
				handler_b.add_or_replace_component<Collision>(Collision{ handler_a, node_b.get_position().xy() });
			}
		}
	}

	auto static_view = m_world.view<Node, StaticBody>(); // Static collision
	for (auto [id_a, node_a] : static_view.each())
	{
		for (auto [id_b, node_b, _] : body_view.each())
		{
			AABB aabb_a{ node_a.get_center().xy(), node_a.get_size() / 2.f };
			AABB aabb_b{ node_b.get_center().xy(), node_b.get_size() / 2.f };

			if (aabb_a.is_intersecting(aabb_b))
			{
				EntityHandler handler_a{ m_world, id_a };
				EntityHandler handler_b{ m_world, id_b };

				handler_a.add_or_replace_component<Collision>(Collision{ handler_b, node_a.get_position().xy() });
				handler_b.add_or_replace_component<Collision>(Collision{ handler_a, node_b.get_position().xy() });
			}
		}
	}

	auto collision_view = m_world.view<Node, Collision>(); // Remove not revelant collision
	for (auto [id_a, node_a, collision] : collision_view.each())
	{
		AABB aabb_a{ node_a.get_center().xy(), node_a.get_size() / 2.f };
		const EntityHandler& id_b = collision.get_collider();

		const Node& node_b = id_b.get<Node>();

		AABB aabb_b{ node_b.get_center().xy(), node_b.get_size() / 2.f };
		if (!aabb_a.is_intersecting(aabb_b))
		{
			EntityHandler handler_a{ m_world, id_a };
			handler_a.remove<Collision>();
		}
	}
}
