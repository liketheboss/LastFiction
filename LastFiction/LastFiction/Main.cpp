#include <SDL.h>
#include <cstdio>
#include <cstdlib>
#include "Game.h"
const int SCREEN_WIDTH = 768;
const int SCREEN_HEIGHT = 720;

int main(int argc, char *argv[]) {
	//The window we'll be rendering to
	SDL_Window* window = nullptr;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0"))
	{
		printf("Warning: Pixel texture filtering not enabled!");
		exit(EXIT_FAILURE);
	}

	//Create window
	window = SDL_CreateWindow("Last Fiction", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	Game* game = new Game(window);
	game->init();

	game->run();

	game->clean();

	return EXIT_SUCCESS;
}