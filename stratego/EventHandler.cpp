//
// Created by alex on 2017.11.22..
//

#include <iostream>
#include "EventHandler.h"
#include "HighLight.h"
#include "Game.h"



void EventHandler::init(SDL_Renderer *renderer) {
    std::shared_ptr<Sprite> highLightTexture = std::make_shared<Sprite>(renderer, "images/highlight.png");
    SDL_Rect rect = {BoardInfo::sideBoardStartX, BoardInfo::sideBoardStartY, 48 ,48};
    this->highLight.reset(new HighLight(highLightTexture, rect));
}

void EventHandler::handleEvent(bool& quit, std::shared_ptr<SideBoard>& sideBoard, SDL_Renderer* renderer) {
    while( SDL_PollEvent( &event ) != 0 )
    {
        //User requests quit
        if (event.type == SDL_QUIT) {
            quit = true;
        }
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            int x;
            int y;
            SDL_GetMouseState(&x, &y);

            if (x > BoardInfo::sideBoardStartX && x < BoardInfo::sideBoardEndX
                && y > BoardInfo::sideBoardStartY && y < BoardInfo::sideBoardEndY) {
                std::shared_ptr<Card> currentCard = sideBoard->getCard(x, y);
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
    }
}
