//
// Created by alex on 2017.11.21..
//

#ifndef STRATEGO_GAMEOBJECT_H
#define STRATEGO_GAMEOBJECT_H


#include <SDL_rect.h>
#include <memory>
#include "../engine/Sprite.h"

class GameObject {
public:
    GameObject() = default;
    virtual ~GameObject() = default;

    virtual void draw(std::unique_ptr<SDL_Renderer, SdlDeleter>& renderer) const = 0;

protected:
    SDL_Rect rect;
    std::shared_ptr<Sprite> sprite;
};


#endif //STRATEGO_GAMEOBJECT_H
