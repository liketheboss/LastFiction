#pragma once
#include "Component.h"

class TilesetComponent : Component
{
public:
	TilesetComponent();
	TilesetComponent(int x, int y, int width, int height);
	~TilesetComponent();

	void render(SDL_Renderer* renderer) override;
};

