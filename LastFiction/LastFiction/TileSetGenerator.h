#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <vector>

enum TileSets
{
	TILE_SET_OVERWORLD = 0,
	TILE_SET_AMOUNT = 1
};

class TileSetGenerator
{
public:
	TileSetGenerator();
	~TileSetGenerator();

	static std::vector<std::vector<SDL_Rect>> generateTileSets();

	static const int TILE_WIDTH;
	static const int TILE_HEIGHT;
	static const std::string PATHS[];
private:
	static const int ROWS[];
	static const int COLUMNS[];
};

