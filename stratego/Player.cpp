//
// Created by alex on 2017.11.07..
//

#include "SpriteCardsResource.h"
#include "Player.h"


Player::Player(const std::string& color, SDL_Renderer* renderer) {
    this->color = color;
    spriteCards.reset(new SpriteCardsResource(this->color, renderer));
    this->generateCards();
}

void Player::generateCards() {
    SDL_Rect rect{50,50, 48, 48};
    // Flag
    std::shared_ptr<Card> card = std::make_shared<Card>(spriteCards->getSprite(SpriteName::FLAG), rect, SpriteName::FLAG);
    cards.push_back(card);

    // Spy
    card.reset(new Card(spriteCards->getSprite(SpriteName::SPY), rect, SpriteName::SPY));
    cards.push_back(card);

    // Scout
    for (int x = 0; x < 8; ++x) {
        card.reset(new Card(spriteCards->getSprite(SpriteName::SCOUT), rect, SpriteName::SCOUT));
        cards.push_back(card);
    }

    // Miner
    for (int x = 0; x < 5; ++x) {
        card.reset(new Card(spriteCards->getSprite(SpriteName::MINER), rect, SpriteName::MINER));
        cards.push_back(card);
    }

    // Sergeant
    for (int x = 0; x < 4; ++x) {
        card.reset(new Card(spriteCards->getSprite(SpriteName::SERGEANT), rect, SpriteName::SERGEANT));
        cards.push_back(card);
    }

    // Liuetenant
    for (int x = 0; x < 4; ++x) {
        card.reset(new Card(spriteCards->getSprite(SpriteName::LIEUTENANT), rect, SpriteName::LIEUTENANT));
        cards.push_back(card);
    }

    // Captain
    for (int x = 0; x < 4; ++x) {
        card.reset(new Card(spriteCards->getSprite(SpriteName::CAPTAIN), rect, SpriteName::CAPTAIN));
        cards.push_back(card);
    }

    // Major
    for (int x = 0; x < 3; ++x) {
        card.reset(new Card(spriteCards->getSprite(SpriteName::MAJOR), rect, SpriteName::MAJOR));
        cards.push_back(card);
    }

    // Colonel
    for (int x = 0; x < 2; ++x) {
        card.reset(new Card(spriteCards->getSprite(SpriteName::COLONEL), rect, SpriteName::COLONEL));
        cards.push_back(card);
    }

    // General
    card.reset(new Card(spriteCards->getSprite(SpriteName::GENERAL), rect, SpriteName::GENERAL));
    cards.push_back(card);

    // Marshall
    card.reset(new Card(spriteCards->getSprite(SpriteName::MARSHALL), rect, SpriteName::MARSHALL));
    cards.push_back(card);

    // Bomb
    for(int x = 0; x < 6; ++x){
        card.reset(new Card(spriteCards->getSprite(SpriteName::BOMB), rect, SpriteName::BOMB));
        cards.push_back(card);
    }
}

