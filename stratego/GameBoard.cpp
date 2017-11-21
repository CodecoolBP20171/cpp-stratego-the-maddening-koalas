//
// Created by alex on 2017.11.07..
//

#include "GameBoard.h"

GameBoard::GameBoard(std::shared_ptr<Sprite> sprite, SDL_Rect& rect) {
    this->sprite = sprite;
    this->rect = rect;
}

void GameBoard::draw(SDL_Renderer *renderer) const {
    SDL_RenderCopy(renderer, sprite->getTexture(), NULL, &rect);
}
