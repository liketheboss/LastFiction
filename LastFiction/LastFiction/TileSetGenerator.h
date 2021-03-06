#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <vector>

enum TileSets
{
	TILE_SET_OVERWORLD = 0,
	TILE_SET_TOWN,
	TILE_SET_AMOUNT
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
	static const std::vector<std::vector<bool>> SOLID;
private:
	static const int ROWS[];
	static const int COLUMNS[];
};

