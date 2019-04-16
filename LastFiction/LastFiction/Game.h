#pragma once
#include <SDL.h>
#include "TextureManager.h"
#include "Map.h"
#include "TileSetGenerator.h"

class Game
{
private:
	bool _quit;

	SDL_Window* _window;
	SDL_Renderer* _renderer;

	TextureManager _textureManager;
	Map _map;

	std::vector<SDL_Texture*> _textures;

	std::vector<std::vector<SDL_Rect>> _tileSets;

public:
	Game(SDL_Window* window);
	~Game();

	SDL_Window* getWindow();

	void init();

	void run();

	void handleEvents();
	void tick();
	void render();
	void clean();

	static const int FRAMES_PER_SECOND;
	static const int FRAME_DELAY;

	static const int HOR_TILES;
	static const int VERT_TILES;
	static const int DISPLAY_TILE_SIZE;
};

