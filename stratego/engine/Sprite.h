#pragma once
#include "SDL.h"
#include <iostream>

class Sprite
{
public:
	Sprite(SDL_Renderer* renderer, const std::string& filename);
    ~Sprite() { SDL_DestroyTexture(texture); }
	SDL_Texture* loadTexture(const std::string& filename, SDL_Renderer* renderer);

    SDL_Texture* getTexture() const { return texture; }

protected:
	SDL_Texture* texture;
};

