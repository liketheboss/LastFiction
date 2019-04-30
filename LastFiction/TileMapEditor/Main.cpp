#include <SDL.h>
#include <cstdio>
#include <cstdlib>
#include "Editor.h"

int main(int argc, char* argv[])
{
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

	Editor editor = Editor("Last Fiction", 768, 768);
	editor.init();

	editor.run();

	editor.clean();

	return EXIT_SUCCESS;
}
