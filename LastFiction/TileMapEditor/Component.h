#pragma once
#include <vector>
#include <SDL.h>

class Component
{
protected:
	int _x{};
	int _y{};
	int _width{};
	int _height{};
public:
	Component();
	Component(int x, int y, int width, int height);

	virtual ~Component();

	virtual void render(SDL_Renderer* renderer) = 0;


	int getX() { return _x; }
	int getY() { return _y; }
	int getWidth() { return _width; }
	int getHeight() { return _height; }
};

