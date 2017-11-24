#ifndef STRATEGO_SPRITE_H
#define STRATEGO_SPRITE_H

#include "SdlDeleter.hpp
#include <iostream>
#include <memory>

class Sprite
{
public:
	Sprite(std::unique_ptr<SDL_Renderer, SdlDeleter>&  renderer, const std::string& filename);
//    ~Sprite() { if (texture) SDL_DestroyTexture(texture); }
	std::unique_ptr<SDL_Texture, SdlDeleter> loadTexture(const std::string& filename, std::unique_ptr<SDL_Renderer, SdlDeleter>& renderer);

	std::unique_ptr<SDL_Texture, SdlDeleter>  getTexture() const { return texture; }

protected:
	std::unique_ptr<SDL_Texture, SdlDeleter>  texture;
};

#endif // STRATEGO_SPRITE_H