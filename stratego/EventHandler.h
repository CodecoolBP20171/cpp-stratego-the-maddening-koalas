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
    EventHandler(std::shared_ptr<MouseClick> mc){ this->mc = mc; }
    void handleEvent(bool& quit, std::shared_ptr<SideBoard>& sideBoard);

private:
    std::shared_ptr<MouseClick> mc;
    SDL_Event event;
};


#endif //STRATEGO_EVENTHANDLER_H
