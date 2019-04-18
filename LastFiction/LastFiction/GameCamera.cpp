#include "GameCamera.h"
#include "Handler.h"



GameCamera::GameCamera()
{
}

GameCamera::GameCamera(Handler* handler, int xOffset, int yOffset)
{
	_handler = handler;
	setXOffset(xOffset);
	setYOffset(yOffset);
}


GameCamera::~GameCamera()
{
}

void GameCamera::centerOnEntity(Entity e)
{
	setXOffset(e.getX() - Game::LOGICAL_WIDTH / 2 + Game::DISPLAY_TILE_SIZE);
	setYOffset(e.getY() - 3 - Game::LOGICAL_HEIGHT / 2 + Game::DISPLAY_TILE_SIZE);
}

void GameCamera::move(int xAmt, int yAmt)
{
	_xOffset += xAmt;
	_yOffset += yAmt;
}
