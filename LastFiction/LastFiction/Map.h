#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <SDL.h>
#include "TileSetGenerator.h"
#include "Handler.h"

class Map
{
private:
	std::vector<std::vector<int>> _grid;
	std::string _name;
	TileSets _setType;

	SDL_Texture* _tileSet;
	std::vector<SDL_Rect> _srcTiles;

	Handler* _handler;
public:
	Map(Handler* handler, std::string& file, std::string name, TileSets setType, SDL_Texture* tileSet, std::vector<SDL_Rect> srcTiles);
	Map(Handler* handler, std::vector<std::vector<int>> grid, std::string name, TileSets setType, SDL_Texture* tileSet, std::vector<SDL_Rect> srcTiles);
	~Map();

	void loadMap(std::string& file);

	void render();

	std::string getName() { return _name; }
	std::vector<std::vector<int>> getGrid() { return _grid; }
};

