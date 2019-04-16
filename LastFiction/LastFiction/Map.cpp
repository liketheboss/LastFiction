#include "Map.h"
#include "Game.h"
#include "Tile.h"


Map::Map(Handler* handler, std::string& file, std::string name, TileSets setType, SDL_Texture* tileSet, std::vector<SDL_Rect> srcTiles)
{
	_handler = handler;
	_name = name;
	_setType = setType;
	_tileSet = tileSet;
	_srcTiles = srcTiles;
	loadMap(file);
}

Map::~Map()
= default;

void Map::loadMap(std::string& file)
{
	std::ifstream mapFile(file);
	std::string line;

	int set;
	std::getline(mapFile, line);
	std::stringstream lineStream(line);
	lineStream >> set;

	int y = 0;
	_grid = std::vector<std::vector<Tile*>>();
	while(std::getline(mapFile, line))
	{
		lineStream = std::stringstream(line);

		int x = 0;
		int tid;
		std::vector<Tile*> layer{};
		while (lineStream >> tid)
		{
			bool solid = TileSetGenerator::SOLID[set][tid];
			Tile* tile = new Tile(this, tid, solid, _tileSet, _srcTiles[tid], {
				x * Game::DISPLAY_TILE_SIZE, y * Game::DISPLAY_TILE_SIZE, Game::DISPLAY_TILE_SIZE,
				Game::DISPLAY_TILE_SIZE
				});

			layer.emplace_back(tile);

			x++;
		}
		_grid.emplace_back(layer);

		y++;
	}
	mapFile.close();
}

void Map::render()
{
	for (auto& y : _grid)
	{
		for (auto& x : y)
		{
			x->render();
		}
	}
}
