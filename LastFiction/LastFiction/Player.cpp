#include "Player.h"
#include "Game.h"


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
		                                     Game::LOGICAL_WIDTH / 2 - Game::DISPLAY_TILE_SIZE,
		                                     Game::LOGICAL_HEIGHT / 2 - 3, Game::DISPLAY_TILE_SIZE,
		                                     Game::DISPLAY_TILE_SIZE
	                                     });
}
