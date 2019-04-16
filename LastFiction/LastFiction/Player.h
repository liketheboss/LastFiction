#pragma once
#include "Entity.h"
class Player :
	public Entity
{
public:
	Player(Handler* handler, SDL_Texture* texture, int x, int y);
	~Player();

	void render() override;
};

