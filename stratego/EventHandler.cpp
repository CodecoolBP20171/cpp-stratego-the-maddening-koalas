//
// Created by alex on 2017.11.22..
//

#include "EventHandler.h"

EventHandler::EventHandler(std::shared_ptr<MouseClick> mc, std::shared_ptr<SideBoard> sideBoard) {
    this->mc = mc;
    this->sideBoard = sideBoard;
}

void EventHandler::handleEvent(bool& quit, Color player, GameState state) {
    while( SDL_PollEvent( &event ) != 0 )
    {
        //User requests quit
        if (event.type == SDL_QUIT) {
            quit = true;
        }
        if (event.type == SDL_MOUSEBUTTONDOWN) {

            SDL_GetMouseState(mc->clickX(), mc->clickY());

            if(state == GameState::setupPhase){
                handlePrepPhase();
            } else if(state == GameState::gamePhase){
                handleGameLoop();
            }
        }
    }
}

void EventHandler::handlePrepPhase() const {
    if (mc->getClickX() > BoardInfo::sideBoardStartX && mc->getClickX() < BoardInfo::sideBoardEndX
        && mc->getClickY() > BoardInfo::sideBoardStartY && mc->getClickY() < BoardInfo::sideBoardEndY) {
                std::shared_ptr<Card> currentCard = sideBoard->getCard(mc->getClickX(), mc->getClickY());
                if (currentCard) {
//                    SDL_RenderDrawRect()
                }

                std::cout << "X: " << mc->getClickX() << " Y: " << mc->getClickY() << std::endl;
            }
}

void EventHandler::handleGameLoop() {
    //TODO if click inside the game board do stuff dude! Need some move handling on the cards validation etc.. too doh...
}
