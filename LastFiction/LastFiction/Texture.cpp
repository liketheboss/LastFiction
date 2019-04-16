#include "Tile.h"

Tile::Tile(SDL_Texture* texture, SDL_Rect renderQuad)
{
	_sdlTexture = texture;
	_renderQuad = renderQuad;
}

Tile::~Tile()
= default;

bool Tile::loadFromFile(std::string path)
{
	return false;
}

void Tile::free()
{
}

void Tile::render(SDL_Renderer * renderer, SDL_Rect * clip)
{
}

SDL_Rect Tile::getRenderQuad()
{
	return _renderQuad;
}
