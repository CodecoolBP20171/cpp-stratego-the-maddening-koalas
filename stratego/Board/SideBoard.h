//
// Created by bekor on 11/21/17.
//

#ifndef STRATEGO_SIDEBOARD_H
#define STRATEGO_SIDEBOARD_H

#include "../Player.h"

class SideBoard {
public:
    SideBoard(){ set = false; }
    ~SideBoard() = default;

    void setPlayerCards(std::shared_ptr<Player> player);
    void removePlayerCard(std::shared_ptr<Card> card);
    std::array< std::array<std::shared_ptr<Card>, 5>, 8> getBoard() { return board; }
    std::shared_ptr<Card> getCard(int& x, int& y);
    bool isSet(){ return set; }
    bool doneSet(){ set = true; }
    bool reSet(){ set = false; }

private:
    bool set;
    std::array< std::array<std::shared_ptr<Card>, 5>, 8> board;
};


#endif //STRATEGO_SIDEBOARD_H
