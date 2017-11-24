#include "Sprite.h"
#include "SDL_image.h"


Sprite::Sprite(std::unique_ptr<SDL_Renderer, SdlDeleter>& renderer, const std::string& filename) {
    this->loadTexture(filename, renderer);
}

std::unique_ptr<SDL_Texture, SdlDeleter> Sprite::loadTexture(const std::string& filename, std::unique_ptr<SDL_Renderer, SdlDeleter>&  renderer)
{
	texture = std::unique_ptr<SDL_Texture, SdlDeleter>(
			IMG_LoadTexture_RW(renderer.get(), SDL_RWFromFile(filename.c_str(), "rb"), 1),
			SdlDeleter());

	if (texture == nullptr)
	{
		printf("File not found: %s SDL_image Error: %s\n,", filename.c_str(), IMG_GetError());
	}

	return texture;
}