#pragma once
#include <SDL.h>
#include "TextureManager.h"
#include "Map.h"
#include "TileSetGenerator.h"
#include "Player.h"
#include "GameCamera.h"

class Handler;

class Game
{
private:
	bool _quit;

	std::string _title;
	int _width;
	int _height;

	SDL_Window* _window;
	SDL_Renderer* _renderer;

	TextureManager _textureManager;
	GameCamera _gameCamera;

	//TESTING
	Player _player;
	Map _map;

	std::vector<SDL_Texture*> _textures;
	std::vector<std::vector<SDL_Rect>> _tileSets;

	Handler* _handler;

public:
	Game(std::string title, int width, int height);
	~Game();

	SDL_Window* getWindow() { return _window; };
	void setWindow(std::string title, int width, int height);

	void init();

	void run();

	void handleEvents();
	void tick();
	void render();
	void clean();

	int getWidth() { return _width; }
	int getHeight() { return _height; }

	GameCamera getGameCamera() { return _gameCamera; }
	TextureManager getTextureManager() { return _textureManager; }
	SDL_Renderer* getRenderer() { return _renderer; }

	static const int FRAMES_PER_SECOND;
	static const int FRAME_DELAY;

	static const int HOR_TILES;
	static const int VERT_TILES;
	static const int DISPLAY_TILE_SIZE;

	static const int LOGICAL_WIDTH;
	static const int LOGICAL_HEIGHT;
};

