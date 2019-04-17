#pragma once
#include <string>
#include <SDL.h>
#include <map>
#include <SDL_image.h>
#include "TileSetGenerator.h"

class Handler;

enum TileType
{
	TILE_GRASS = 0
};

class TextureManager
{
private:
	Handler* _handler;
public:
	TextureManager();
	TextureManager(Handler* handler);

	SDL_Texture* loadTexture(std::string path);
	//Renders tile at given point
	void render(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);

};

