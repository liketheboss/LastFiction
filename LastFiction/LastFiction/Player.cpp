#include "Player.h"


Player::Player() : Entity(nullptr, nullptr, 0, 0)
{
}

Player::Player(Handler* handler, SDL_Texture* texture, int x, int y) : Entity(handler, texture, x, y)
{
}

Player::~Player()
{
}

void Player::render()
{
	_handler->getTextureManager().render(_texture, {32, 32, 16, 16},
	                                     {
		                                     _x - _handler->getGameCamera().getXOffset(),
											 _y - _handler->getGameCamera().getYOffset(), Game::DISPLAY_TILE_SIZE,
		                                     Game::DISPLAY_TILE_SIZE
	                                     });
}
