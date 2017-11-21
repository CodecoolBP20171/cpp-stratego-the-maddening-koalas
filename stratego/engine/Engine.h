#ifndef STRATEGO_ENGINE_H
#define STRATEGO_ENGINE_H

#include "SDL.h"
#include "Scene.h"
#include <iostream>

class Engine
{
public:
	Engine();
	~Engine();

	bool init(const char* title, int windowWidth, int windowHeight);
	SDL_Window* getWindow() { return window; }
	SDL_Renderer* getRenderer() { return renderer; }
	void getWindowSize(int& width, int& height);
	bool createWindow(const char* title, int windowWidth, int windowHeight);
	bool createRenderer();
	bool initSDLImage();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};

#endif // STRATEGO_ENGINE_H