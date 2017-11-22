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

            SDL_GetMouseState(mc->clickX(), mc->clickY());

            if (mc->getClickX() > BoardInfo::sideBoardStartX && mc->getClickX() < BoardInfo::sideBoardEndX
                && mc->getClickY() > BoardInfo::sideBoardStartY && mc->getClickY() < BoardInfo::sideBoardEndY) {
                std::shared_ptr<Card> currentCard = sideBoard->getCard(mc->getClickX(), mc->getClickY());
                if (currentCard) {
//                    SDL_RenderDrawRect()
                }

                std::cout << "X: " << mc->getClickX() << " Y: " << mc->getClickY() << std::endl;
            }
        }
    }
}
