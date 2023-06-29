#include <iostream>

#include "Tilemap.hpp"

int main()
{
	TileMap tilemap = TileMap::LoadFromFile("stage_1.json");

	std::cout << "Hello world" << std::endl;

	return 0;
}