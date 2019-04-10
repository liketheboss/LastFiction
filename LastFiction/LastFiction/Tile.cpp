#include "Tile.h"



Tile::Tile()
= default;


Tile::~Tile()
= default;

void Tile::render(const int x, const int y, SDL_Renderer * renderer, SDL_Rect * clip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, _width, _height };

	//Set clip rendering dimensions
	if (clip != nullptr)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopy(renderer, _sdlTexture, clip, &renderQuad);
}
