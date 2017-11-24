//
// Created by alex on 2017.11.07..
//

#ifndef STRATEGO_CARD_H
#define STRATEGO_CARD_H

#include "../engine/Sprite.h"
#include "GameObject.hpp"

class Card : public GameObject {
public:
    Card(std::shared_ptr<Sprite>& cardFace, std::shared_ptr<Sprite>& cardBack, SDL_Rect& rect, int& type);
    ~Card() = default;

    void draw(std::unique_ptr<SDL_Renderer, SdlDeleter>&  renderer) const override;

    int getType() const { return type; }

    void setPosition(int x, int y) { rect.x = x; rect.y = y; }
    int getPosX() { return rect.x; }
    int getPosY() { return rect.y; }

    const bool isFaceDown() { return faceDown; }
    void flipCard(){ faceDown = !faceDown; }


private:
    std::shared_ptr<Sprite> cardBack;
    int type;
    bool faceDown;
};

#endif //STRATEGO_CARD_H
