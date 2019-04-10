#pragma once
#include <string>
#include "TileSheet.h"
class Map
{
public:
	Map(std::string file, TileSheet tileSheet, std::string name);
	~Map();
};

