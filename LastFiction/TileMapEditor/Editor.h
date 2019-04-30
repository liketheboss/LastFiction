#pragma once
#include <string>
#include <SDL.h>
#include "Component.h"

class Editor
{
private:
	bool _quit{};

	std::string _title;
	int _width{};
	int _height{};

	SDL_Window* _window{};
	SDL_Renderer* _renderer{};

	std::vector<Component> components;
public:
	Editor();
	Editor(std::string title, int width, int height);
	~Editor();

	void setWindow(std::string title, int width, int height);
	void init();

	void run();

	void handleEvents();
	void tick();
	void render();
	void clean();


	static const int FRAMES_PER_SECOND;
	static const int FRAME_DELAY;

	static const int LOGICAL_WIDTH;
	static const int LOGICAL_HEIGHT;
};

