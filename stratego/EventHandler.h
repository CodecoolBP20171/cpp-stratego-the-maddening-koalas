//
// Created by alex on 2017.11.22..
//

#ifndef STRATEGO_EVENTHANDLER_H
#define STRATEGO_EVENTHANDLER_H


#include <SDL_events.h>
#include "SideBoard.h"
#include "MouseClick.hpp"

class EventHandler {
public:
    EventHandler(std::shared_ptr<MouseClick> mc, std::shared_ptr<SideBoard> sideBoard);
//    ~EventHandler();
    void handleEvent(bool& quit, Color player, GameState state);
private:

    std::shared_ptr<SideBoard> sideBoard;
    std::shared_ptr<MouseClick> mc;
    SDL_Event event;

    void handleGameLoop();
    void handlePrepPhase() const;
};


#endif //STRATEGO_EVENTHANDLER_H
