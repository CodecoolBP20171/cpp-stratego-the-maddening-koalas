//
// Created by alex on 2017.11.07..
//

#include "Card.h"

Card::Card(Sprite& sprite, SDL_Rect& rect, int value){}

Card::~Card() {
    //this->destroy();
}

void Card::draw(SDL_Renderer *renderer) {
    SDL_RenderCopy(renderer, sprite, NULL, &rect);
}
