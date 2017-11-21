//
// Created by alex on 2017.11.07..
//

#include "SpriteCardsResource.h"
#include "Player.h"


Player::Player(const std::string &color, SDL_Renderer* renderer) {
    spriteCards.reset(new SpriteCardsResource(color, renderer));
    this->generateCards();
}

void Player::generateCards() {
    for(int y= 0; y < 3; ++y) {
        for (int x = 0; x < 3; ++x) {
            SDL_Rect rect{x * 50 + 1 ,y * 50 + 1 , 48, 48};
            std::shared_ptr<Card> card = std::make_shared<Card>(spriteCards->getSprite(SpriteName::BOMB), rect, 11);
            cards.push_back(card);
        }
    }
}

