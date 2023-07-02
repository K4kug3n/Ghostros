#include "TileSet.hpp"

TileSet::TileSet(std::filesystem::path filepath, uint16_t tilesize, std::vector<Tile> tiles)
	: m_filepath(std::move(filepath))
	, m_texture()
	, m_tilesize(tilesize)
	, m_tiles(std::move(tiles))
{
	if (!m_texture.loadFromFile(m_filepath.generic_string()))
	{
		std::runtime_error("Can't load Texture from file " + m_filepath.generic_string());
	}
}

bool TileSet::get_collision(uint8_t id) const
{
	return m_tiles[id].collide;
}

const sf::Texture& TileSet::get_texture() const
{
	return m_texture;
}

Vector2u TileSet::get_texture_index(uint8_t id) const
{
	return Vector2u{ m_tiles[id].texture_u_idx, m_tiles[id].texture_v_idx };
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
		tiles.push_back(Tile{ tile["texture_u_idx"], tile["texture_v_idx"], tile["collide"]});
	}

	return TileSet{ data["path"], data["tilesize"], std::move(tiles)};
}
