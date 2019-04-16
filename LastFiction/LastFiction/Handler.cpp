#include "Handler.h"
#include "Game.h"


Handler::Handler(Game* game)
{
	setGame(game);
}

Handler::~Handler()
= default;

int Handler::getWidth()
{
	return _game->getWidth();
}

int Handler::getHeight()
{
	return _game->getHeight();
}

TextureManager Handler::getTextureManager()
{
	return _game->getTextureManager();
}

Game* Handler::getGame()
{
	return _game;
}

void Handler::setGame(Game* game)
{
	_game = game;
}


