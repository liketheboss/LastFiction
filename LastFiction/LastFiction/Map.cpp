#include "Map.h"


Map::Map()
= default;

Map::Map(std::string file, std::string name)
{

}

Map::Map(std::vector<std::vector<std::string>> grid, std::string name)
{
	_grid = grid;
	_name = name;
}

Map::~Map()
= default;
