#pragma once
#include "Component.h"
class TopBarComponent :
	public Component
{
public:
	TopBarComponent();
	TopBarComponent(int x, int y, int width, int height);
	~TopBarComponent();

	void render(SDL_Renderer* renderer) override;
};

