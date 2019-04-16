#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <map>

class TileSetGenerator
{
public:
	TileSetGenerator();
	~TileSetGenerator();

	static std::map<std::string, SDL_Rect> generateTiles();
private:
	static const std::string FOREST_PATH;
	static const std::string OVERWORLD_PATH;
	static const std::string PLATEAU_PATH;
};

