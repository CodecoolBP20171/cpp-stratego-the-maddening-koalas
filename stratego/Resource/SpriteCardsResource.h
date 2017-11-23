//
// Created by alex on 2017.11.21..
//

#ifndef STRATEGO_INITSPRITE_H
#define STRATEGO_INITSPRITE_H


#include <vector>
#include <memory>
#include <string>

#include "StrategoEnum.h"
#include "../engine/Sprite.h"

class SpriteCardsResource {
public:
    SpriteCardsResource(const Color& color, SDL_Renderer* renderer) { this->generateSprites(color, renderer); }
    ~SpriteCardsResource() = default;

    void generateSprites(const Color& color, SDL_Renderer* renderer);
    std::shared_ptr<Sprite> getSprite(SpriteName name);


private:
    std::vector<std::shared_ptr<Sprite>> strategoSprites;

    void generateNeutralSprites(SDL_Renderer* renderer);

    void genearetPlayerCards(SDL_Renderer *renderer, const std::string &playerColor);
};


#endif //STRATEGO_INITSPRITE_H
