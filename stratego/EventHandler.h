//
// Created by alex on 2017.11.22..
//

#ifndef STRATEGO_EVENTHANDLER_H
#define STRATEGO_EVENTHANDLER_H


#include <SDL_events.h>
#include "SideBoard.h"

class EventHandler {
public:
    void handleEvent(bool& quit, std::shared_ptr<SideBoard>& sideBoard);

private:
    SDL_Event event;
};


#endif //STRATEGO_EVENTHANDLER_H