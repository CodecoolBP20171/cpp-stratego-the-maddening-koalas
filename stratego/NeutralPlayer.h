//
// Created by bekor on 11/23/17.
//

#ifndef STRATEGO_NEUTRALPLAYER_H
#define STRATEGO_NEUTRALPLAYER_H

#include <vector>
#include "GameObject/Card.h"
#include "Resource/SpriteCardsResource.h"

class NeutralPlayer {
public:
    NeutralPlayer(const Color& color, SDL_Renderer* renderer);
    ~NeutralPlayer() = default;
    Color getColor(){ return color; }

    std::vector< std::shared_ptr<Card> > getCards() const { return cards; }

private:
    void generateCards();
    Color color;
    std::vector< std::shared_ptr<Card> > cards;
    std::unique_ptr<SpriteCardsResource> spriteCards;
};


#endif //STRATEGO_NEUTRALPLAYER_H
