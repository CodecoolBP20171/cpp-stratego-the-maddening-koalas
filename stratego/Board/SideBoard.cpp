//
// Created by bekor on 11/21/17.
//

#include "SideBoard.h"

void SideBoard::setPlayerCards(std::shared_ptr<Player>& player) {
    for (unsigned colY = 0; colY < 8; ++colY) {
        for (unsigned colX = 0; colX < 5; ++colX) {
            player->getCards()[colX+colY * 5]->setPosition(BoardInfo::sideBoardStartX + colX * BoardInfo::cardWidth,
                                                           BoardInfo::sideBoardStartY + colY * BoardInfo::cardHeigth);
            board[colY][colX] = player->getCards()[colX+colY * 5];
            ++amountofCards;
        }
    }
}

std::shared_ptr<Card> SideBoard::getCard(int& x, int& y) {
    for (auto &col : board) {
        for (auto &card : col) {
            if ( card
                 && ((card->getPosX() < x && card->getPosX() + BoardInfo::cardWidth > x)
                 && (card->getPosY() < y && card->getPosY() + BoardInfo::cardWidth > y)))
            {
                return card;
            }
        }
    }
    return nullptr;
}

void SideBoard::removePlayerCard(std::shared_ptr<Card>& card) {
    for (unsigned colY = 0; colY < 8; ++colY) {
        for (unsigned colX = 0; colX < 5; ++colX) {
            if(card == board[colY][colX]){
                board[colY][colX] = nullptr;
                --amountofCards;
                return;
            }
        }
    }
}

bool SideBoard::isCardOnSide(std::shared_ptr<Card>& card) {
    for (unsigned colY = 0; colY < 8; ++colY) {
        for (unsigned colX = 0; colX < 5; ++colX) {
            if(card == board[colY][colX]){
                return true;
            }
        }
    }
    return false;
}
