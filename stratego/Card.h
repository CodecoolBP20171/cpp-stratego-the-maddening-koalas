//
// Created by alex on 2017.11.07..
//

#ifndef STRATEGO_CARD_H
#define STRATEGO_CARD_H

#include "engine/Sprite.h"
#include "GameObject.hpp"

class Card : public GameObject {
public:
    Card(std::shared_ptr<Sprite> sprite, SDL_Rect& rect, int type);
    ~Card() = default;
    void draw(SDL_Renderer* renderer) const override;
    int getType() const { return type; }
    void setPosition(int x, int y) { rect.x = x; rect.y = y; }

private:
    int type;
};

#endif //STRATEGO_CARD_H
