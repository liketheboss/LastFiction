#pragma once
#include "Entity.h"
#include "Game.h"

class Handler;

class GameCamera
{
private:
	Handler* _handler;

	int _xOffset;
	int _yOffset;
public:
	GameCamera();
	GameCamera(Handler* handler, int xOffset, int yOffset);
	~GameCamera();

	void centerOnEntity(Entity e);
	void move(int xAmt, int yAmt);


	int getXOffset() { return _xOffset; }
	void setXOffset(int xOffset) { _xOffset = xOffset; }

	int getYOffset() { return _yOffset; }
	void setYOffset(int yOffset) { _yOffset = yOffset; }
};

