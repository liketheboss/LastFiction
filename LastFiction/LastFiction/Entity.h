#pragma once
#include <SDL.h>
#include "Handler.h"

class Entity
{
protected:
	Handler* _handler;

	SDL_Texture* _texture;
	int _x, _y;

public:
	Entity(Handler* handler, SDL_Texture* texture, int x, int y);
	virtual ~Entity();

	int getX() { return _x; }
	int getY() { return _y; }
	virtual void render();
};

