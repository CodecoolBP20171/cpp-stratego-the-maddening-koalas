//
// Created by alex on 2017.11.22..
//

#ifndef STRATEGO_HIGHLIGHT_H
#define STRATEGO_HIGHLIGHT_H

#include "GameObject.hpp"

class HighLight : public GameObject {
public:
    HighLight(std::shared_ptr<Sprite> sprite, SDL_Rect& rect);
    ~HighLight() = default;
    void setPosition(int posX, int posY);
    void draw(SDL_Renderer* renderer) const override;
};


#endif //STRATEGO_HIGHLIGHT_H
