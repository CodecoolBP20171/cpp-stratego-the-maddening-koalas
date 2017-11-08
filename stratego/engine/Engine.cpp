#include "Engine.h"
#include "SDL_image.h"


Engine::Engine() : window(nullptr) {}

Engine::~Engine()
{
	if (renderer) SDL_DestroyRenderer(renderer);
	if (window) SDL_DestroyWindow(window);
	SDL_Quit();
}

bool Engine::init(const char* title, int windowWidth, int windowHeight)
{
	if (SDL_Init(SDL_INIT_VIDEO != 0))
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
	}
	std::cout << "SDL_Init" << std::endl;
	if (!createWindow(title, windowWidth, windowHeight)) return false;
	if (!createRenderer()) return false;
	if (!initSDLImage()) return false;
	return true;
}

bool Engine::createWindow(const char* title, int windowWidth, int windowHeight)
{
	window = SDL_CreateWindow(title, 100, 100, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return false;
	}
	std::cout << "SDL_CreateWindow" << std::endl;
	return true;
}

bool Engine::createRenderer()
{
	if (!window) return false;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr)
	{
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return false;
	}
	std::cout << "SDL_CreateRenderer" << std::endl;
	return true;
}

bool Engine::initSDLImage()
{
	int imgFlags = IMG_INIT_PNG;
	if ((!IMG_Init(imgFlags))& imgFlags)
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return false;
	}
	std::cout << "SDL_Init_Image" << std::endl;
	return true;
}

void Engine::getWindowSize(int& width, int& height)
{
	SDL_GetWindowSize(window, &width, &height);
}