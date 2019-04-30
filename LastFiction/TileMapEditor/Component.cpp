#include "Component.h"



Component::Component()
= default;

Component::Component(int x, int y, int width, int height)
{
	_x = x;
	_y = y;
	_width = width;
	_height = height;
}

Component::~Component()
= default;
