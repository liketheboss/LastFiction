#pragma once
#include "Texture.h"

class Tile : Texture
{
public:
	Tile();
	~Tile();

	//Renders texture at given point
	void render(int x, int y, SDL_Renderer *renderer, SDL_Rect* clip = nullptr);
};

