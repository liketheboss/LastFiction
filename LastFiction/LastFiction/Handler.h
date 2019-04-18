#pragma once
#include "TextureManager.h"
#include "GameCamera.h"

class Game;

class Handler
{
private:
	Game* _game;

public:
	Handler(Game* game);
	~Handler();

	int getWidth();
	int getHeight();

	GameCamera getGameCamera();
	TextureManager getTextureManager();
	SDL_Renderer* getRenderer();

	Game* getGame();
	void setGame(Game* game);
	
};

