#ifndef GRAPHICS_TILESET_HPP
#define GRAPHICS_TILESET_HPP

#include <filesystem>
#include <vector>

#include <nlohmann/json.hpp>

#include "Graphics/Texture.hpp"
#include "Graphics/Tile.hpp"
#include "Maths/Vector2.hpp"

class TileSet
{
public:
	TileSet() = delete;
	TileSet(const std::filesystem::path& filepath, uint16_t tilesize, std::vector<Tile> tiles);
	TileSet(const TileSet&) = delete;
	TileSet(TileSet&&) = default;
	~TileSet() = default;

	TileProperties get_properties(uint8_t id) const;
	const Texture& get_texture() const;
	Vector2u get_texture_index(uint8_t id) const;
	uint16_t get_tile_size() const;

	static TileSet LoadFromJson(const nlohmann::json& data);

	TileSet& operator=(const TileSet&) = delete;
	TileSet& operator=(TileSet&&) = default;

private:
	Texture m_texture;

	uint16_t m_tilesize;
	std::vector<Tile> m_tiles;
};

#endif