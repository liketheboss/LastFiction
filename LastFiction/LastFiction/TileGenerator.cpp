#include "TileSetGenerator.h"

const std::string TileSetGenerator::FOREST_PATH = "Resources/forest.png";
const std::string TileSetGenerator::OVERWORLD_PATH = "Resources/overworld.png";
const std::string TileSetGenerator::PLATEAU_PATH = "Resources/plateau.png";

TileSetGenerator::TileSetGenerator()
= default;


TileSetGenerator::~TileSetGenerator()
= default;

std::map<std::string, SDL_Rect> TileSetGenerator::generateTiles(SDL_Renderer* renderer)
{
	return NULL;
}
