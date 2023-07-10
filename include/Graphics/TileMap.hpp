#ifndef GRAPHICS_TILEMAP_HPP
#define GRAPHICS_TILEMAP_HPP

#include <filesystem>
#include <vector>

#include <SFML/Graphics/VertexArray.hpp>

#include "Graphics/TileSet.hpp"
#include "Graphics/SceneItem.hpp"
#include "Maths/Vector2.hpp"

class RenderWindow;

class TileMap : public SceneItem
{
public:
	TileMap() = delete;
	TileMap(unsigned cols, unsigned rows, std::vector<uint8_t> indices, TileSet tile_set);
	TileMap(const TileMap&) = delete;
	TileMap(TileMap&&) = default;
	~TileMap() = default;

	void draw(RenderWindow& window);
	uint8_t get_cell_id(unsigned x, unsigned y) const;
	void update(RenderWindow& window, InputHandler& input_handler, double delta_time) override;
	Vector2i world_to_map(const Vector2i& position) const;

	static TileMap LoadFromFile(const std::filesystem::path& filepath);

	TileMap& operator=(const TileMap&) = delete;
	TileMap& operator=(TileMap&&) = default;

private:
	unsigned m_rows;
	unsigned m_cols;
	std::vector<uint8_t> m_indices;

	sf::VertexArray m_vertices;

	TileSet m_tile_set;
};

#endif