//
// Created by alex on 2017.11.07..
//

#include "GameBoard.h"

GameBoard::GameBoard(std::shared_ptr<NeutralPlayer>& neutral) {
    this->neutral = neutral;
    for (unsigned colY = 0; colY < 10; ++colY) {
        for (unsigned colX = 0; colX < 10; ++colX) {
            board[colY][colX] = neutral->getCards()[colX + colY * 10];
        }
    }
}

void GameBoard::init(std::shared_ptr<Player> &player) {
    if(player->getColor() == Color::red){
        for (unsigned colY = 0; colY < 4; ++colY) {
            for (unsigned colX = 0; colX < 10; ++colX) {
                board[colY][colX]->flipCard();
            }
        }
    }
}

std::shared_ptr<Card> GameBoard::getCard(int &x, int &y) {
    for (auto &col : board) {
        for (auto &card : col) {
            if ( (card->getPosX() < x && card->getPosX() + BoardInfo::cardWidth > x)
                 && (card->getPosY() < y && card->getPosY() + BoardInfo::cardWidth > y) ) {
                return card;
            }
        }
    }
    return NULL;
}

void GameBoard::setCard(std::shared_ptr<Card> card) {
    for (auto &col : board) {
        for (auto &cb : col) {
            if ( cb->getPosX() == card->getPosX() && cb->getPosY() == card->getPosY()) {
                cb = card;
            }
        }
    }
}

