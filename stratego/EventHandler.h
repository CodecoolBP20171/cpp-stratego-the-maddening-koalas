//
// Created by alex on 2017.11.22..
//

#ifndef STRATEGO_EVENTHANDLER_H
#define STRATEGO_EVENTHANDLER_H


#include <SDL_events.h>
#include "SideBoard.h"
#include "HighLight.h"

class EventHandler {
public:
    void init(SDL_Renderer* renderer);
    void handleEvent(bool& quit, std::shared_ptr<SideBoard>& sideBoard, SDL_Renderer* renderer);
    std::shared_ptr<HighLight> getHighLight() { return highLight; }

private:
    SDL_Event event;
    std::shared_ptr<HighLight> highLight;
    bool isHighLighted = false;
};


#endif //STRATEGO_EVENTHANDLER_H
