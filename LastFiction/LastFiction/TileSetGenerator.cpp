#include "TileSetGenerator.h"

const std::string TileSetGenerator::PATHS[] = {"Resources/overworld.png"};
const int TileSetGenerator::ROWS[] = { 8 };
const int TileSetGenerator::COLUMNS[] = { 14 };
const int TileSetGenerator::TILE_WIDTH = 16;
const int TileSetGenerator::TILE_HEIGHT = 16;

TileSetGenerator::TileSetGenerator()
= default;


TileSetGenerator::~TileSetGenerator()
= default;

std::vector<std::vector<SDL_Rect>> TileSetGenerator::generateTileSets()
{

	std::vector<std::vector<SDL_Rect>> tileSets;
	for (int i = 0; i < TILE_SET_AMOUNT; i++)
	{
		std::vector<SDL_Rect> tiles;
		for (int j = 0, row = 0, column = 0; j < ROWS[i] * COLUMNS[i]; j++)
		{
			tiles.push_back({column * TILE_WIDTH, row * TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT});
			if (column == COLUMNS[i])
			{
				column = 0;
				row++;
			}
			else
			{
				column++;
			}
		}
		tileSets.push_back(tiles);
	}

	return tileSets;
}
