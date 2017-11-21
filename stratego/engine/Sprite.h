#ifndef STRATEGO_SPRITE_H
#define STRATEGO_SPRITE_H

#include "SDL.h"
#include <iostream>

class Sprite
{
public:
	Sprite(SDL_Renderer* renderer, const std::string& filename);
    ~Sprite() { if (texture) SDL_DestroyTexture(texture); }
	SDL_Texture* loadTexture(const std::string& filename, SDL_Renderer* renderer);

    SDL_Texture* getTexture() const { return texture; }

protected:
	SDL_Texture* texture;
};

#endif // STRATEGO_SPRITE_H