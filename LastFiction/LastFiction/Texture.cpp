#include "Texture.h"



Texture::Texture(): _sdlTexture(nullptr), _width(0), _height(0)
{
}


Texture::~Texture()
= default;

bool Texture::loadFromFile(std::string path)
{
	return false;
}

void Texture::free()
{
}

void Texture::render(int x, int y, SDL_Renderer * renderer, SDL_Rect * clip)
{
}

int Texture::getWidth()
{
	return _width;
}

int Texture::getHeight()
{
	return _height;
}
