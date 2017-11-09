#include "Sprite.h"
#include "SDL_image.h"


Sprite::Sprite(SDL_Renderer* renderer, const std::string& filename) {
    this->loadTexture(filename, renderer);
}

SDL_Texture* Sprite::loadTexture(const std::string& filename, SDL_Renderer* renderer)
{
	texture = IMG_LoadTexture_RW(renderer, SDL_RWFromFile(filename.c_str(), "rb"), 1);

	if (texture == nullptr)
	{
		printf("File not found: %s SDL_image Error: %s\n,", filename.c_str(), IMG_GetError());
	}

	return texture;
}