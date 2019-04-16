#include "Entity.h"


Entity::Entity(Handler* handler, SDL_Texture* texture, int x, int y)
{
	_handler = handler;
	_texture = texture;
	_x = x;
	_y = y;
}

Entity::~Entity()
{
}
