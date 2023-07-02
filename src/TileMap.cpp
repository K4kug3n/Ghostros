#include "TileMap.hpp"

#include <fstream>
#include <string>

#include <nlohmann/json.hpp>

#include "Window/RenderWindow.hpp"

using json = nlohmann::json;

TileMap::TileMap(unsigned cols, unsigned rows, std::vector<uint8_t> map, TileSet tile_set)
	: m_cols(cols)
	, m_rows(rows)
	, m_indices(std::move(map))
	, m_vertices(sf::Triangles, cols * rows * 6)
	, m_tile_set(std::move(tile_set))
{
	for (unsigned i = 0; i < cols; ++i)
	{
		for (unsigned j = 0; j < rows; ++j)
		{
			uint8_t tile_id = get_cell_id(i, j);
			Vector2u texture_idx = m_tile_set.get_texture_index(tile_id);

			sf::Vertex* triangles = &m_vertices[(i + j * cols) * 6];
			uint16_t tilesize = m_tile_set.get_tilesize();

			triangles[0].position = sf::Vector2f(i * tilesize, j * tilesize);
			triangles[1].position = sf::Vector2f((i + 1) * tilesize, j * tilesize);
			triangles[2].position = sf::Vector2f(i * tilesize, (j + 1) * tilesize);
			triangles[3].position = sf::Vector2f(i * tilesize, (j + 1) * tilesize);
			triangles[4].position = sf::Vector2f((i + 1) * tilesize, j * tilesize);
			triangles[5].position = sf::Vector2f((i + 1) * tilesize, (j + 1) * tilesize);

			// on définit ses 6 coordonnées de textexture_idx.xre correspondantes
			triangles[0].texCoords = sf::Vector2f(texture_idx.x * tilesize, texture_idx.x * tilesize);
			triangles[1].texCoords = sf::Vector2f((texture_idx.x + 1) * tilesize, texture_idx.x * tilesize);
			triangles[2].texCoords = sf::Vector2f(texture_idx.x * tilesize, (texture_idx.x + 1) * tilesize);
			triangles[3].texCoords = sf::Vector2f(texture_idx.x * tilesize, (texture_idx.x + 1) * tilesize);
			triangles[4].texCoords = sf::Vector2f((texture_idx.x + 1) * tilesize, texture_idx.x * tilesize);
			triangles[5].texCoords = sf::Vector2f((texture_idx.x + 1) * tilesize, (texture_idx.x + 1) * tilesize);
		}
	}
}

void TileMap::draw(RenderWindow& window)
{
	window.draw(m_vertices, sf::RenderStates{ &m_tile_set.get_texture() });
}

uint8_t TileMap::get_cell_id(unsigned x, unsigned y) const
{
	return m_indices[y * m_cols + x];
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
