#include "TileSet.hpp"

TileSet::TileSet(std::filesystem::path filepath, uint16_t tilesize, std::vector<Tile> tiles)
	: m_filepath(std::move(filepath))
	, m_tilesize(tilesize)
	, m_tiles(std::move(tiles))
{}

bool TileSet::get_tile_collision(uint8_t id) const
{
	assert(id < m_tiles.size());
	return m_tiles[id].collide;
}

uint16_t TileSet::get_tilesize() const
{
	return m_tilesize;
}

TileSet TileSet::LoadFromJson(const nlohmann::json & data)
{
	std::vector<Tile> tiles;
	for (auto&& tile : data["tiles"])
	{
		tiles.push_back(Tile{ tile["top_left_x"], tile["top_left_y"], tile["collide"]});
	}

	return TileSet{ data["path"], data["tilesize"], std::move(tiles)};
}
