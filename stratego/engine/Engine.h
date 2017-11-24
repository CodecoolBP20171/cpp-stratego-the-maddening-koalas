#ifndef STRATEGO_ENGINE_H
#define STRATEGO_ENGINE_H

#include "SdlDeleter.hpp"
#include "Scene.h"
#include <iostream>

class Engine
{
public:
	Engine();
	~Engine();

	bool init(const char* title, int windowWidth, int windowHeight);
	std::unique_ptr<SDL_Window, SdlDeleter>  getWindow() { return window; }
	std::unique_ptr<SDL_Renderer, SdlDeleter>  getRenderer() { return renderer; }
	void getWindowSize(int& width, int& height);
	bool createWindow(const char *title, int x, int y, int width, int height, Uint32 flag);
	bool createRenderer();
	bool initSDLImage();

private:
	std::unique_ptr<SDL_Window, SdlDeleter> window;
	std::unique_ptr<SDL_Renderer, SdlDeleter> renderer;

//	std::unique_ptr<SDL_Window, SdlDeleter> create_window(const char *title, int x, int y, int width, int height, Uint32 flag);
};

#endif // STRATEGO_ENGINE_H