#pragma once
#include <string>
#include <vector>
#include <SDL.h>


class Map
{
private:
	std::vector<std::vector<std::string>> _grid;
	std::string _name;
public:
	Map();
	Map(std::string file, std::string name);
	Map(std::vector<std::vector<std::string>> grid, std::string name);
	~Map();

	std::string getName() { return _name; }
	std::vector<std::vector<std::string>> getGrid() { return _grid; }
};

