//
// Created by bekor on 11/22/17.
//

#ifndef STRATEGO_BACKGROUND_H
#define STRATEGO_BACKGROUND_H


#include "../GameObject/GameObject.hpp"

class Background: public GameObject{
public:
    Background(std::shared_ptr<Sprite> sprite, SDL_Rect& rect);
    ~Background() = default;
    void draw(SDL_Renderer* renderer) const override;
};


#endif //STRATEGO_BACKGROUND_H
