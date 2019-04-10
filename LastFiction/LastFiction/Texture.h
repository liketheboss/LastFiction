#pragma once
#include <string>
#include <SDL.h>

class Texture
{
public:
	//Initializes variables
	Texture();

	//Deallocates memory
	~Texture();

	//Loads image at specified path
	bool loadFromFile(std::string path);

	//Deallocates texture
	void free();

	//Renders texture at given point
	void render(int x, int y, SDL_Renderer *renderer, SDL_Rect* clip = nullptr);

	//Gets image dimensions
	int getWidth();
	int getHeight();

protected:
	//The actual hardware texture
	SDL_Texture * _sdlTexture{};

	//Image dimensions
	int _width{};
	int _height{};
};

