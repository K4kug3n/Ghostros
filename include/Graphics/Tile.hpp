#ifndef GRAPHICS_TILE_HPP
#define GRAPHICS_TILE_HPP

#include <cstdint>

#include "Graphics/TileProperties.hpp"

struct Tile
{
	uint16_t texture_u_idx;
	uint16_t texture_v_idx;
	TileProperties properties;
};

#endif