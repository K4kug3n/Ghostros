#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <filesystem>
#include <vector>

#include "TileSet.hpp"
#include "Maths/Vector2.hpp"

class TileMap
{
public:
	TileMap() = delete;
	TileMap(unsigned cols, unsigned rows, std::vector<uint8_t> map, TileSet tile_set);
	TileMap(const TileMap&) = delete;
	TileMap(TileMap&&) = default;
	~TileMap() = default;

	uint8_t get_cell_id(int x, int y) const;
	Vector2i world_to_map(const Vector2i& position) const;

	static TileMap LoadFromFile(const std::filesystem::path& filepath);

	TileMap& operator=(const TileMap&) = delete;
	TileMap& operator=(TileMap&&) = default;

private:
	unsigned m_rows;
	unsigned m_cols;

	std::vector<uint8_t> m_map;

	TileSet m_tile_set;
};

#endif