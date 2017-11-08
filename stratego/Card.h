//
// Created by alex on 2017.11.07..
//

#ifndef STRATEGO_CARD_H
#define STRATEGO_CARD_H


#include "engine/Sprite.h"

class Card {
public:
    Card(Sprite& sprite, SDL_Rect& rect, int type);
    ~Card();
    void draw(SDL_Renderer* renderer);
    int getType() const { return type; }
    void setPosition(int x, int y) { rect.x += x; rect.y += y; }

private:
    int type;
    SDL_Rect rect;
    Sprite* texture;
};

#endif //STRATEGO_CARD_H
