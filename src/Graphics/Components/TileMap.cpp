#include "Graphics/Components/TileMap.hpp"

#include <fstream>
#include <string>

#include <nlohmann/json.hpp>

#include "Graphics/RenderWindow.hpp"

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
			uint16_t tilesize = m_tile_set.get_tile_size();

			triangles[0].position = sf::Vector2f{ static_cast<float>(i * tilesize), static_cast<float>(j * tilesize) };
			triangles[1].position = sf::Vector2f{ static_cast<float>((i + 1) * tilesize), static_cast<float>(j * tilesize) };
			triangles[2].position = sf::Vector2f{ static_cast<float>(i * tilesize), static_cast<float>((j + 1) * tilesize) };
			triangles[3].position = sf::Vector2f{ static_cast<float>(i * tilesize), static_cast<float>((j + 1) * tilesize) };
			triangles[4].position = sf::Vector2f{ static_cast<float>((i + 1) * tilesize), static_cast<float>(j * tilesize) };
			triangles[5].position = sf::Vector2f{ static_cast<float>((i + 1) * tilesize), static_cast<float>((j + 1) * tilesize) };

			triangles[0].texCoords = sf::Vector2f{ static_cast<float>(texture_idx.x * tilesize), static_cast<float>(texture_idx.x * tilesize) };
			triangles[1].texCoords = sf::Vector2f{ static_cast<float>((texture_idx.x + 1) * tilesize), static_cast<float>(texture_idx.x * tilesize) };
			triangles[2].texCoords = sf::Vector2f{ static_cast<float>(texture_idx.x * tilesize), static_cast<float>((texture_idx.x + 1) * tilesize) };
			triangles[3].texCoords = sf::Vector2f{ static_cast<float>(texture_idx.x * tilesize), static_cast<float>((texture_idx.x + 1) * tilesize) };
			triangles[4].texCoords = sf::Vector2f{ static_cast<float>((texture_idx.x + 1) * tilesize), static_cast<float>(texture_idx.x * tilesize) };
			triangles[5].texCoords = sf::Vector2f{ static_cast<float>((texture_idx.x + 1) * tilesize), static_cast<float>((texture_idx.x + 1) * tilesize) };
		}
	}
}

TileMap::TileMap(TileMap&& other) noexcept
	: m_cols(other.m_cols)
	, m_rows(other.m_rows)
	, m_indices(std::move(other.m_indices))
	, m_vertices(std::move(other.m_vertices))
	, m_tile_set(std::move(other.m_tile_set))
{
}

void TileMap::draw(RenderWindow& window)
{
	window.draw(m_vertices, sf::RenderStates{ &m_tile_set.get_texture().get_handle() });
}

AABB TileMap::get_AABB(unsigned x, unsigned y) const
{
	const uint16_t tile_size = m_tile_set.get_tile_size();
	const uint16_t half = tile_size / 2;
	return AABB{ 
		Vector2f{ static_cast<float>(x * tile_size + half), static_cast<float>(y * tile_size + half) },
		Vector2f{ static_cast<float>(half), static_cast<float>(half) }
	};
}

uint8_t TileMap::get_cell_id(unsigned x, unsigned y) const
{
	return m_indices[y * m_cols + x];
}

const TileSet& TileMap::get_tile_set() const
{
	return m_tile_set;
}

Vector2i TileMap::world_to_map(const Vector2f& position) const
{
	return Vector2i{ static_cast<int>(position.x / m_tile_set.get_tile_size()), static_cast<int>(position.y / m_tile_set.get_tile_size()) };
}

TileMap TileMap::LoadFromFile(const std::filesystem::path& filepath)
{
	std::ifstream map_file{ filepath };

	const json map_json = json::parse(map_file);

	return TileMap{ map_json["cols"], map_json["rows"], map_json["map"], TileSet::LoadFromJson(map_json["tileset"]) };
}

TileMap& TileMap::operator=(TileMap&& other) noexcept
{
	m_cols = other.m_cols;
	m_rows = other.m_rows;
	m_indices = std::move(other.m_indices);
	m_vertices = std::move(other.m_vertices);
	m_tile_set = std::move(other.m_tile_set);

	return *this;
}
