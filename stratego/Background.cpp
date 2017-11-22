//
// Created by bekor on 11/22/17.
//

#include "Background.h"

Background::Background(std::shared_ptr<Sprite> sprite, SDL_Rect &rect) {
    this->sprite = sprite;
    this->rect = rect;
}

void Background::draw(SDL_Renderer *renderer) const {
    SDL_RenderCopy(renderer, sprite->getTexture(), NULL, &rect);
}
