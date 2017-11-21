//
// Created by alex on 2017.11.07..
//

#include "Card.h"

Card::Card(std::shared_ptr<Sprite> sprite, SDL_Rect& rect, int value) {
    this->sprite = sprite;
    this->rect = rect;
    this->type = value;
}

void Card::draw(SDL_Renderer *renderer) const {
    SDL_RenderCopy(renderer, sprite->getTexture(), NULL, &rect);
}
