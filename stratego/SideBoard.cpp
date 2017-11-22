//
// Created by bekor on 11/21/17.
//

#include "SideBoard.h"

void SideBoard::setPlayerCards(std::shared_ptr<Player> player) {
    for (unsigned colY = 0; colY < 8; ++colY) {
        for (unsigned colX = 0; colX < 5; ++colX) {
            player->getCards()[colX+colY * 5]->setPosition(505 + colX * 48, 111 + colY * 48);
            board[colY][colX] = player->getCards()[colX+colY * 5];
        }
    }
}