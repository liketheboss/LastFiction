#include "Game.h"

const int Game::FRAMES_PER_SECOND = 60;
const int Game::FRAME_DELAY = 1000 / FRAMES_PER_SECOND;

const int Game::HOR_TILES = 16;
const int Game::VERT_TILES = 15;
const int Game::DISPLAY_TILE_SIZE = 16;

Game::Game(SDL_Window* window)
{
	_window = window;
	_quit = false;
}

Game::~Game()
= default;

SDL_Window* Game::getWindow()
{
	return this->_window;
}

void Game::init()
{
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	//Initialize renderer color
	SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	//Initialize PNG loading
	IMG_Init(IMG_INIT_PNG);
	SDL_RenderSetLogicalSize(_renderer, 256, 240);

	_textureManager = TextureManager(_renderer);
	_tileSets = TileSetGenerator::generateTileSets();

	std::vector<std::vector<std::string>> map = std::vector<std::vector<std::string>>();
	for (int i = 0; i < HOR_TILES; i++)
	{
		std::vector<std::string> row = std::vector<std::string>();
		for (int i = 0; i < VERT_TILES; i++)
		{
			std::string thing = std::to_string(rand() % 10);
			row.emplace_back(thing);
		}
		map.push_back(row);
	}
	_map = Map(map, "Basic Map");

	_textures = std::vector<SDL_Texture*>();
	for (int i = 0; i < TILE_SET_AMOUNT; i++)
	{
		_textures.push_back(_textureManager.loadTexture(TileSetGenerator::PATHS[i]));
	}
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

	int size = int(_map.getGrid().size());
	for (int x = 0; x < size; x++)
	{
		int ysize = int(_map.getGrid()[x].size());
		for (int y = 0; y < ysize; y++)
		{
			_textureManager.render(_textures[0], _tileSets[TILE_SET_OVERWORLD][std::stoi(_map.getGrid()[x][y])], {
				x*DISPLAY_TILE_SIZE, y*DISPLAY_TILE_SIZE, DISPLAY_TILE_SIZE, DISPLAY_TILE_SIZE});
		}
	}
	SDL_RenderPresent(_renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	SDL_Quit();
}
