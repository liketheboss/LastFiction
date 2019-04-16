#include "Tile.h"
#include "TextureManager.h"
#include "Map.h"


Tile::Tile(Map* map, const int tid, bool solid, SDL_Texture* tileSet, SDL_Rect src, SDL_Rect dest)
{
	_map = map;
	_tid = tid;
	_solid = solid;
	_tileSet = tileSet;
	_src = src;
	_dest = dest;
}

Tile::~Tile()
{
}

void Tile::render()
{
	_map->getHandler()->getTextureManager()->render(_tileSet, _src, _dest);
}
