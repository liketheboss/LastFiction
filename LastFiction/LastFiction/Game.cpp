#include "Game.h"
#include "Handler.h"

const int Game::FRAMES_PER_SECOND = 60;
const int Game::FRAME_DELAY = 1000 / FRAMES_PER_SECOND;

const int Game::HOR_TILES = 16;
const int Game::VERT_TILES = 15;
const int Game::DISPLAY_TILE_SIZE = 16;

Game::Game(std::string title, int width, int height)
{
	setWindow(title, width, height);
	_title = title;
	_width = width;
	_height = height;
}

Game::~Game()
= default;

void Game::setWindow(std::string title, int width, int height)
{
	_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (_window == nullptr)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

void Game::init()
{
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	IMG_Init(IMG_INIT_PNG);

	SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderSetLogicalSize(_renderer, 256, 240);

	_handler = new Handler(this);
	_textureManager = TextureManager(_renderer);
	_tileSets = TileSetGenerator::generateTileSets();

	_textures = std::vector<SDL_Texture*>();
	for (int i = 0; i < TILE_SET_AMOUNT; i++)
	{
		_textures.push_back(_textureManager.loadTexture(TileSetGenerator::PATHS[i]));
	}

	std::string path = "Resources/corneria_overworld.txt";
	_map = new Map(_handler, path, std::string("corneria_overworld"),
		TILE_SET_OVERWORLD, _textures[TILE_SET_OVERWORLD], _tileSets[TILE_SET_OVERWORLD]);

	_quit = false;
}

void Game::run()
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

void Game::handleEvents()
{
	SDL_Event e;
	SDL_PollEvent(&e);

	switch (e.type)
	{
	case SDL_QUIT:
		_quit = true;
		break;
	default:
		break;
	}
}

void Game::tick()
{
}

void Game::render()
{
	//Clear screen
	SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(_renderer);

	_map->render();

	SDL_RenderPresent(_renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	SDL_Quit();
}
