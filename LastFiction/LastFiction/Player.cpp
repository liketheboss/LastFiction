#include "Player.h"


Player::Player(Handler* handler, SDL_Texture* texture, int x, int y) : Entity(handler, texture, x, y)
{
}

Player::~Player()
{
}

void Player::render()
{
	_handler->getTextureManager()->render(_texture, { 0, 0, 16, 16 }, { _handler->getWidth() / 2, _handler->getHeight() / 2, 32, 32 });
}
