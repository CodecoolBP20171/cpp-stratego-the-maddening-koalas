//
// Created by alex on 2017.11.07..
//

#ifndef STRATEGO_GAMEBOARD_H
#define STRATEGO_GAMEBOARD_H


#include "../GameObject/GameObject.hpp"
#include "../Player.h"

class GameBoard  {
public:
    GameBoard();
    ~GameBoard() = default;

    void init(std::shared_ptr<Player>& player);

private:
    std::array< std::array<std::shared_ptr<Card>, 10>, 10> board;
};


#endif //STRATEGO_GAMEBOARD_H
