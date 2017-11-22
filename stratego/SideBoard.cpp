//
// Created by bekor on 11/21/17.
//

#include "SideBoard.h"

void SideBoard::setPlayerCards(std::shared_ptr<Player> player) {
    for(auto card : player->getCards()){
        card->setPosition(10, 10);
    }
}
