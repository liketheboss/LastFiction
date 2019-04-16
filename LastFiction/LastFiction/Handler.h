#pragma once
#include "TextureManager.h"

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
	TextureManager* getTextureManager();

	Game* getGame();
	void setGame(Game* game);
	
};

