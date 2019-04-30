#include "Editor.h"
#include <SDL_image.h>

const int Editor::FRAMES_PER_SECOND = 60;
const int Editor::FRAME_DELAY = 1000 / FRAMES_PER_SECOND;

const int Editor::LOGICAL_WIDTH = 256;
const int Editor::LOGICAL_HEIGHT = 256;

Editor::Editor()
= default;

Editor::Editor(std::string title, int width, int height)
{
	setWindow(title, width, height);
	_quit = false;
	_title = title;
	_width = width;
	_height = height;
}


Editor::~Editor()
= default;

void Editor::setWindow(std::string title, int width, int height)
{
	_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (_window == nullptr)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

void Editor::init()
{
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	IMG_Init(IMG_INIT_PNG);

	SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderSetLogicalSize(_renderer, LOGICAL_WIDTH, LOGICAL_HEIGHT);
}

void Editor::run()
{
	while (!_quit)
	{
		const int frameStart = SDL_GetTicks();

		handleEvents();
		tick();
		render();

		const int frameTime = SDL_GetTicks() - frameStart;

		if (FRAME_DELAY > frameTime)
		{
			SDL_Delay(FRAME_DELAY - frameTime);
		}
	}
}

void Editor::handleEvents()
{
}

void Editor::tick()
{
}

void Editor::render()
{
	for (auto& comp : components)
	{
		comp.render(_renderer);
	}
}

void Editor::clean()
{
}
