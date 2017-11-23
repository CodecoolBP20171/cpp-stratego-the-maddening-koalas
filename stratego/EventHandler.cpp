//
// Created by alex on 2017.11.22..
//

#include "EventHandler.h"

EventHandler::EventHandler(std::shared_ptr<MouseClick>& mc,
                           std::shared_ptr<SideBoard>& sideBoard,
                           std::shared_ptr<HighLight>& highlight) {
    this->highLight = highlight;
    this->mc = mc;
    this->sideBoard = sideBoard;
}

void EventHandler::init(SDL_Renderer *renderer) {
    std::shared_ptr<Sprite> highLightTexture = std::make_shared<Sprite>(renderer, "images/highlight.png");
    SDL_Rect rect = {BoardInfo::sideBoardStartX, BoardInfo::sideBoardStartY, 48 ,48};
    highLight->setSprite(highLightTexture, rect);
}
// Modify it!!!!
// void EventHandler::handleEvent(bool& quit, Color player, GameState state) 

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
                && mc->getClickY() > BoardInfo::sideBoardStartY && mc->getClickY() < BoardInfo::sideBoardEndY)
    {
        std::shared_ptr<Card> currentCard = sideBoard->getCard(mc->getClickX(), mc->getClickY());
        if (currentCard) {
            if (isHighLighted) {
                highLight->setPosition(currentCard->getPosX(), currentCard->getPosY());
            }
            else {
                highLight->setPosition(currentCard->getPosX(), currentCard->getPosY());
                isHighLighted = true;
            }
        }
    }
}

void EventHandler::handleGameLoop() {
    //TODO if click inside the game board do stuff dude! Need some move handling on the cards validation etc.. too doh...
    //TODO #1 check if click is on the board
    //implement flow chart :D Mannn this is crazy.
    //Ma mind telling me nooooooOO but my body telling me YeeEEEeeeeSsss.
}
