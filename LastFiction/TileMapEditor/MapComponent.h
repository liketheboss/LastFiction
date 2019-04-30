#pragma once
#include "Component.h"

class MapComponent : Component
{
private:

public:
	MapComponent();
	MapComponent(int x, int y, int width, int height);
	~MapComponent();

	void render(SDL_Renderer* renderer) override;
};

