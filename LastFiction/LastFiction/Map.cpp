#include "Map.h"
#include "Game.h"


Map::Map(Handler* handler, std::string& file, std::string name, TileSets setType, SDL_Texture* tileSet, std::vector<SDL_Rect> srcTiles)
{
	_handler = handler;
	_name = name;
	_setType = setType;
	_tileSet = tileSet;
	_srcTiles = srcTiles;
	loadMap(file);
}

Map::Map(Handler* handler, std::vector<std::vector<int>> grid, std::string name, TileSets setType, SDL_Texture* tileSet,
         std::vector<SDL_Rect> srcTiles)
{
	_handler = handler;
	_grid = grid;
	_name = name;
	_setType = setType;
	_tileSet = tileSet;
	_srcTiles = srcTiles;
}

Map::~Map()
= default;

void Map::loadMap(std::string& file)
{
	std::ifstream mapFile(file);
	std::string line;

	std::getline(mapFile, line);


	_grid = std::vector<std::vector<int>>();
	while(std::getline(mapFile, line))
	{
		std::stringstream lineStream(line);

		int tid;
		std::vector<int> layer{};
		while (lineStream >> tid)
		{
			layer.emplace_back(tid);
		}
		_grid.emplace_back(layer);
	}
	mapFile.close();
}

void Map::render()
{
	for (int y = 0; y < int(_grid.size()); y++)
	{
		for (int x = 0; x < int(_grid[y].size()); x++)
		{
			_handler->getTextureManager().render(_tileSet, _srcTiles[_grid[y][x]], {
				x * Game::DISPLAY_TILE_SIZE, y * Game::DISPLAY_TILE_SIZE, Game::DISPLAY_TILE_SIZE,
				Game::DISPLAY_TILE_SIZE
			});
		}
	}
}
