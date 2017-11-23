//
// Created by alex on 2017.11.22..
//

#ifndef STRATEGO_EVENTHANDLER_H
#define STRATEGO_EVENTHANDLER_H


#include <SDL_events.h>
#include "SideBoard.h"
#include "MouseClick.hpp"
#include "HighLight.h"

class EventHandler {
public:
  // add shared pointers by reference
  //TODO ADD RENDERER TO EVENT HANDLER!!!!!
    EventHandler(std::shared_ptr<MouseClick>& mc, std::shared_ptr<SideBoard>& sideBoard);
//    ~EventHandler();
    void handleEvent(bool& quit, Color player, GameState state);

    void init(SDL_Renderer* renderer);
    void handleEvent(bool& quit, std::shared_ptr<SideBoard>& sideBoard, SDL_Renderer* renderer);
    std::shared_ptr<HighLight> getHighLight() { return highLight; }

private:

    std::shared_ptr<SideBoard> sideBoard;
    std::shared_ptr<MouseClick> mc;
    SDL_Event event;

    void handleGameLoop();
    void handlePrepPhase() const;

    std::shared_ptr<HighLight> highLight;
    bool isHighLighted = false;

};


#endif //STRATEGO_EVENTHANDLER_H
