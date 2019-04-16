#pragma once
#include <string>
#include <SDL.h>
#include <map>

class Tile
{
public:
	//Initializes variables
	Tile(SDL_Texture* texture, int width, int height);

	//Deallocates memory
	~Tile();

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
	SDL_Texture* _sdlTexture;

	//Image dimensions
	int _width;
	int _height;

};

