//
// Created by alex on 2017.11.22..
//

#include "EventHandler.h"

EventHandler::EventHandler(std::shared_ptr<SideBoard>& sideBoard,
                           std::shared_ptr<HighLight>& highlight) {
    this->highLight = highlight;
    mc = std::make_shared<MouseClick>();
    currentCard = nullptr;
    this->sideBoard = sideBoard;
}

void EventHandler::init(SDL_Renderer *renderer, std::shared_ptr<GameBoard>& gameBoard) {
    this->gameBoard = gameBoard;

    std::shared_ptr<Sprite> highLightTexture = std::make_shared<Sprite>(renderer, "images/highlight.png");
    SDL_Rect rect = {BoardInfo::sideBoardStartX, BoardInfo::sideBoardStartY, 48 ,48};
    highLight->setSprite(highLightTexture, rect);
}

void EventHandler::handleEvent(bool& quit, Color& player, GameState& state) {

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
    int x = mc->getClickX();
    int y = mc->getClickY();
    if (x > BoardInfo::sideBoardStartX && x < BoardInfo::sideBoardEndX
                && y > BoardInfo::sideBoardStartY && y < BoardInfo::sideBoardEndY)
    {
       currentCard = sideBoard->getCard(x, y);
        if (currentCard) {
            if (isHighLighted) {
                highLight->setPosition(currentCard->getPosX(), currentCard->getPosY());
            }
            else {
                highLight->setPosition(currentCard->getPosX(), currentCard->getPosY());
                isHighLighted = true;
            }
        }
    } else {
        std::shared_ptr<Card> boardCard = gameBoard->getCard(x, y);
        if(currentCard && boardCard){
            //TODO Validity TEST!!!!!!!!!!!!!!!
            std::cout << "Card: " << currentCard->getType()
                      << "Face: " << boardCard->isFaceDown() << std::endl;
            currentCard->setPosition(boardCard->getPosX(), boardCard->getPosY());
            gameBoard->setCard(currentCard);
//            currentCard = nullptr;
        } else  {
            std::cout << "Board: " << currentCard << std::endl;
        }
    }
}

void EventHandler::handleGameLoop() {
    //TODO if click inside the game board do stuff dude! Need some move handling on the cards validation etc.. too doh...
    //TODO #1 check if click is on the board
    //implement flow chart :D Mannn this is crazy.
    //Ma mind telling me nooooooOO but my body telling me YeeEEEeeeeSsss.
}
