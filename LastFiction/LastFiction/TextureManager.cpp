#include "TextureManager.h"

TextureManager::TextureManager()
{
}

TextureManager::TextureManager(SDL_Renderer* renderer): _renderer(renderer) {}

SDL_Texture* TextureManager::loadTexture(std::string path)
{
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == nullptr)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	//Color key image
	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

	//Create texture from surface pixels
	SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
	if (texture == nullptr)
	{
		printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
	}

	//Get rid of old loaded surface
	SDL_FreeSurface(loadedSurface);

	return texture;
}

void TextureManager::render(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(_renderer, texture, &src, &dest);
}
