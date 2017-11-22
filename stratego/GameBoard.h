//
// Created by alex on 2017.11.07..
//

#ifndef STRATEGO_GAMEBOARD_H
#define STRATEGO_GAMEBOARD_H


#include "GameObject.hpp"
#include "Card.h"

class GameBoard  {
public:
    GameBoard();
    ~GameBoard() = default;

private:
    std::array< std::array<std::weak_ptr<Card>, 10>, 10> board;
};


#endif //STRATEGO_GAMEBOARD_H
