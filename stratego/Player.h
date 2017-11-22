//
// Created by alex on 2017.11.07..
//

#ifndef STRATEGO_PLAYER_H
#define STRATEGO_PLAYER_H

#include "Card.h"
#include <vector>
#include "SpriteCardsResource.h"

class Player {
public:
    Player(const std::string& color, SDL_Renderer* renderer);
    ~Player() = default;

    std::vector< std::shared_ptr<Card> > getCards() const { return cards; }

private:
    std::string color;
    std::vector< std::shared_ptr<Card> > cards;
    std::unique_ptr<SpriteCardsResource> spriteCards;
    void generateCards();
};


#endif //STRATEGO_PLAYER_H
