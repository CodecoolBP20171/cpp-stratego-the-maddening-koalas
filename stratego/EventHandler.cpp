//
// Created by alex on 2017.11.22..
//

#include <iostream>
#include "EventHandler.h"
#include "Game.h"

void EventHandler::handleEvent(bool& quit, std::shared_ptr<SideBoard>& sideBoard) {
    SDL_Event e;
    while( SDL_PollEvent( &e ) != 0 )
    {
        //User requests quit
        if (e.type == SDL_QUIT) {
            quit = true;
        }
        if (e.type == SDL_MOUSEBUTTONDOWN) {
            int x;
            int y;
            SDL_GetMouseState(&x, &y);

            if (x > BoardInfo::sideBoardStartX && x < BoardInfo::sideBoardEndX
                && y > BoardInfo::sideBoardStartY && y < BoardInfo::sideBoardEndY) {
                std::shared_ptr<Card> currentCard = sideBoard->getCard(x, y);
                if (currentCard) {
                    SDL_RenderDrawRect()
                }

                std::cout << "X: " << x << " Y: " << y << std::endl;
            }
        }
    }
}
