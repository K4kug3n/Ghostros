#ifndef TILESET_HPP
#define TILESET_HPP

#include <filesystem>
#include <vector>
#include <unordered_map>

#include <nlohmann/json.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Maths/Vector2.hpp"

class TileSet
{
public:
	struct Tile {
		uint16_t texture_u_idx;
		uint16_t texture_v_idx;
		bool collide;
	};

	TileSet() = delete;
	TileSet(std::filesystem::path filepath, uint16_t tilesize, std::vector<Tile> tiles);
	TileSet(const TileSet&) = delete;
	TileSet(TileSet&&) = default;
	~TileSet() = default;

	bool get_collision(uint8_t id) const;
	const sf::Texture& get_texture() const;
	Vector2u get_texture_index(uint8_t id) const;
	uint16_t get_tilesize() const;

	static TileSet LoadFromJson(const nlohmann::json& data);

	TileSet& operator=(const TileSet&) = delete;
	TileSet& operator=(TileSet&&) = default;

private:	
	std::filesystem::path m_filepath;
	sf::Texture m_texture;

	uint16_t m_tilesize;
	std::vector<Tile> m_tiles;
};

#endif