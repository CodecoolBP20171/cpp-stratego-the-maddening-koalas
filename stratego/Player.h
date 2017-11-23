//
// Created by alex on 2017.11.07..
//

#ifndef STRATEGO_PLAYER_H
#define STRATEGO_PLAYER_H

#include "GameObject/Card.h"
#include <vector>
#include "Resource/SpriteCardsResource.h"

class Player {
public:
    Player(const Color& color, SDL_Renderer* renderer);
    ~Player() = default;
    Color getColor(){ return color; }

    std::vector< std::shared_ptr<Card> > getCards() const { return cards; }

private:
    Color color;
    std::vector< std::shared_ptr<Card> > cards;
    std::unique_ptr<SpriteCardsResource> spriteCards;
    void generateCards();
};


#endif //STRATEGO_PLAYER_H
