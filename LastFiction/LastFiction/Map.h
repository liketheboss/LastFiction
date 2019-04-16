#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <SDL.h>
#include "TileSetGenerator.h"
#include "Handler.h"

class Tile;

class Map
{
private:
	std::vector <std::vector<Tile*>> _grid;
	std::string _name;
	TileSets _setType;

	SDL_Texture* _tileSet;
	std::vector<SDL_Rect> _srcTiles;

	Handler* _handler;

	void loadMap(std::string& file);
public:
	Map(Handler* handler, std::string& file, std::string name, TileSets setType, SDL_Texture* tileSet, std::vector<SDL_Rect> srcTiles);
	~Map();

	void render();

	std::string getName() { return _name; }
	std::vector<std::vector<Tile*>> getGrid() { return _grid; }

	Handler* getHandler() { return _handler; }
};

