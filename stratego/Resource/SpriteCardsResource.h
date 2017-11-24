//
// Created by alex on 2017.11.21..
//

#ifndef STRATEGO_INITSPRITE_H
#define STRATEGO_INITSPRITE_H


#include <vector>
#include <string>

#include "StrategoEnum.h"
#include "../engine/Sprite.h"

class SpriteCardsResource {
public:
    SpriteCardsResource(const Color& color, std::unique_ptr<SDL_Renderer, SdlDeleter>&  renderer) { this->generateSprites(color, renderer); }
    ~SpriteCardsResource() = default;

    void generateSprites(const Color& color, std::unique_ptr<SDL_Renderer, SdlDeleter>&  renderer);
    std::shared_ptr<Sprite> getSprite(SpriteName& name);
    std::shared_ptr<Sprite> getSprite(NeutralName& name);


private:
    std::vector<std::shared_ptr<Sprite>> strategoSprites;

    void generateNeutralSprites(std::unique_ptr<SDL_Renderer, SdlDeleter>& renderer);

    void genearetPlayerCards(std::unique_ptr<SDL_Renderer, SdlDeleter>& renderer, const std::string &playerColor);
};


#endif //STRATEGO_INITSPRITE_H
