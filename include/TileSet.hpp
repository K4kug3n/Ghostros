#ifndef TILESET_HPP
#define TILESET_HPP

#include <filesystem>
#include <vector>
#include <unordered_map>

#include <nlohmann/json.hpp>

class TileSet
{
public:
	struct Tile {
		uint16_t top_left_x;
		uint16_t top_left_y;
		bool collide;
	};

	TileSet() = delete;
	TileSet(std::filesystem::path filepath, uint16_t tilesize, std::vector<Tile> tiles);
	TileSet(const TileSet&) = default;
	TileSet(TileSet&&) = default;
	~TileSet() = default;

	bool get_tile_collision(uint8_t id) const;
	uint16_t get_tilesize() const;

	static TileSet LoadFromJson(const nlohmann::json& data);

	TileSet& operator=(const TileSet&) = default;
	TileSet& operator=(TileSet&&) = default;

private:	
	std::filesystem::path m_filepath;

	uint16_t m_tilesize;
	std::vector<Tile> m_tiles;
};

#endif