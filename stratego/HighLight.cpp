//
// Created by alex on 2017.11.22..
//

#include "HighLight.h"

HighLight::HighLight(std::shared_ptr<Sprite> sprite, SDL_Rect &rect) {
    this->sprite = sprite;
    this->rect = rect;
}

void HighLight::draw(SDL_Renderer *renderer) const {
    SDL_RenderCopy(renderer, sprite->getTexture(), NULL, &rect);
}
