#pragma once
#include <SDL.h>

class Map;

class Tile
{
private:
	Map* _map;

	int _tid;

	bool _solid;

	SDL_Texture* _tileSet;
	SDL_Rect _src, _dest;
public:
	Tile(Map* map, const int tid, bool solid, SDL_Texture* tileSet, SDL_Rect src, SDL_Rect dest);
	~Tile();

	void render();
};

