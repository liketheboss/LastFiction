#pragma once
#include "Entity.h"

enum Characters
{
	BLACK_BELT,
	THIEF,
	RED_MAGE,
	FIGHTER,
	BLACK_MAGE,
	WHITE_MAGE,
};

class Player :
	public Entity
{
public:
	Player();
	Player(Handler* handler, SDL_Texture* texture, int x, int y);
	~Player();

	virtual void render() override;
};

