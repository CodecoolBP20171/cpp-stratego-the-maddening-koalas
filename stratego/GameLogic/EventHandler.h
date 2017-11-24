//
// Created by alex on 2017.11.22..
//

#ifndef STRATEGO_EVENTHANDLER_H
#define STRATEGO_EVENTHANDLER_H


#include <SDL_events.h>
#include "../Board/SideBoard.h"
#include "MouseClick.hpp"
#include "../GameObject/HighLight.h"
#include "../Board/GameBoard.h"

class EventHandler {
public:
    EventHandler(std::shared_ptr<SideBoard>& sideBoard,
                 std::shared_ptr<HighLight>& highlight);
//    ~EventHandler();
    void init(std::unique_ptr<SDL_Renderer, SdlDeleter>& renderer, std::shared_ptr<GameBoard>& gameBoard);
    void handleEvent(bool& quit, Color& player, GameState& state);
    std::shared_ptr<HighLight> getHighLight() { return highLight; }

private:

    std::shared_ptr<SideBoard> sideBoard;
    std::shared_ptr<GameBoard> gameBoard;
    std::shared_ptr<MouseClick> mc;
    mutable std::shared_ptr<Card> currentCard;
    SDL_Event event;

    void handleGameLoop();
    void handlePrepPhase() const;

    std::shared_ptr<HighLight> highLight;
    mutable bool isHighLighted = false;

    bool clickIsSideBoard(int &x, int &y) const;
};


#endif //STRATEGO_EVENTHANDLER_H
