//
// Created by bekor on 11/21/17.
//

#ifndef STRATEGO_SIDEBOARD_H
#define STRATEGO_SIDEBOARD_H

#include "Player.h"

class SideBoard {
public:
    SideBoard();
    ~SideBoard() = default;

    void setPlayerCards(std::shared_ptr<Player> player);

private:
    std::array< std::array<std::weak_ptr<Card>, 5>, 8> board;
};


#endif //STRATEGO_SIDEBOARD_H
