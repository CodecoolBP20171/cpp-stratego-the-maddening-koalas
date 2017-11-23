//
// Created by alex on 2017.11.07..
//

#ifndef STRATEGO_GAMEBOARD_H
#define STRATEGO_GAMEBOARD_H


#include "../GameObject/GameObject.hpp"
#include "../Player.h"
#include "../NeutralPlayer.h"

class GameBoard  {
public:
    GameBoard(std::shared_ptr<NeutralPlayer>& neutral);
    ~GameBoard() = default;

    void init(std::shared_ptr<Player>& player);
    std::shared_ptr<Card> getCard(int& x, int& y);
    void flipCards();
    void setCard(std::shared_ptr<Card> card);


private:
    std::shared_ptr<NeutralPlayer> neutral;
    std::array< std::array<std::shared_ptr<Card>, 10>, 10> board;
};


#endif //STRATEGO_GAMEBOARD_H
