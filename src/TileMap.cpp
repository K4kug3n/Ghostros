#include "TileMap.hpp"

#include <fstream>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

TileMap::TileMap(unsigned cols, unsigned rows, std::vector<uint8_t> map, TileSet tile_set)
	: m_cols(cols)
	, m_rows(rows)
	, m_map(std::move(map))
	, m_tile_set(std::move(tile_set))
{}

uint8_t TileMap::get_cell_id(int x, int y) const
{
	return m_map[y * m_cols + x];
}

Vector2i TileMap::world_to_map(const Vector2i& position) const
{
	return Vector2i{ position.x / m_tile_set.get_tilesize(), position.y / m_tile_set.get_tilesize() };
}

TileMap TileMap::LoadFromFile(const std::filesystem::path& filepath)
{
	std::ifstream map_file{ filepath };

	const json map_json = json::parse(map_file);

	return TileMap{ map_json["cols"], map_json["rows"], map_json["map"], TileSet::LoadFromJson(map_json["tileset"]) };
}
