#ifndef GRAPHICS_COMPONENTS_TILEMAP_HPP
#define GRAPHICS_COMPONENTS_TILEMAP_HPP

#include <filesystem>
#include <vector>

#include <SFML/Graphics/VertexArray.hpp>

#include "Graphics/TileSet.hpp"
#include "Maths/Vector2.hpp"
#include "Physics/AABB.hpp"

class RenderWindow;

class TileMap
{
public:
	TileMap() = delete;
	TileMap(unsigned cols, unsigned rows, std::vector<uint8_t> indices, TileSet tile_set);
	TileMap(const TileMap&) = delete;
	TileMap(TileMap&& other) noexcept;
	~TileMap() = default;

	void draw(RenderWindow& window);
	AABB get_AABB(unsigned x, unsigned y) const;
	uint8_t get_cell_id(unsigned x, unsigned y) const;
	const TileSet& get_tile_set() const;
	Vector2i world_to_map(const Vector2f& position) const;

	static TileMap LoadFromFile(const std::filesystem::path& filepath);

	TileMap& operator=(const TileMap&) = delete;
	TileMap& operator=(TileMap&& other) noexcept;

private:
	unsigned m_rows;
	unsigned m_cols;
	std::vector<uint8_t> m_indices;

	sf::VertexArray m_vertices;

	TileSet m_tile_set;
};

#endif