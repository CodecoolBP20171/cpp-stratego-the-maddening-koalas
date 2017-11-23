//
// Created by alex on 2017.11.07..
//

#include "GameBoard.h"

GameBoard::GameBoard() {
    for (unsigned colY = 0; colY < 10; ++colY) {
        for (unsigned colX = 0; colX < 10; ++colX) {
//            board[colY][colX] =
        }
    }
}

void GameBoard::init(std::shared_ptr<Player> &player) {
    if(player->getColor() == Color::red){
        for (unsigned colY = 0; colY < 4; ++colY) {
            for (unsigned colX = 0; colX < 10; ++colX) {
                SDL_Rect rect = {BoardInfo::GameBoardStartX + colX * BoardInfo::cardHeigth,
                                 BoardInfo::GameBoardStartY + colY * BoardInfo::cardWidth,
                                 BoardInfo::cardWidth,
                                 BoardInfo::cardHeigth};
//                board[colY][colX] = std::make_shared<Card>();
            }
        }
    }
}

