//
// Created by alex on 2017.11.07..
//

#include "Card.h"

Card::Card(std::shared_ptr<Sprite> cardFace, std::shared_ptr<Sprite> cardBack, SDL_Rect& rect, int value) {
    this->sprite = cardFace;
    this->cardBack = cardBack;
    this->rect = rect;
    this->type = value;
    faceDown = false;
}

void Card::draw(SDL_Renderer *renderer) const {
    if(faceDown){
        SDL_RenderCopy(renderer, cardBack->getTexture(), NULL, &rect);
    } else{
        SDL_RenderCopy(renderer, sprite->getTexture(), NULL, &rect);
    }
}
