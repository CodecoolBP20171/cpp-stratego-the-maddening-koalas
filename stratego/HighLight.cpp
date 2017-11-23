//
// Created by alex on 2017.11.22..
//

#include "HighLight.h"


void HighLight::draw(SDL_Renderer *renderer) const {
    SDL_RenderCopy(renderer, sprite->getTexture(), NULL, &rect);
}

void HighLight::setSprite(std::shared_ptr<Sprite>& sprite, SDL_Rect &rect) {
    this->sprite = sprite;
    this->rect = rect;
}

void HighLight::setPosition(int posX, int posY) {
    this->rect.x = posX;
    this->rect.y = posY;
}
