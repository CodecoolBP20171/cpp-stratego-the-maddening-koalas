//
// Created by alex on 2017.11.22..
//

#include <iostream>
#include "EventHandler.h"

void EventHandler::handleEvent(bool& quit) {
    SDL_Event e;
    while( SDL_PollEvent( &e ) != 0 )
    {
        //User requests quit
        if (e.type == SDL_QUIT) {
            quit = true;
        }
        if (e.type == SDL_MOUSEBUTTONDOWN) {
            int x;
            int y;
            SDL_GetMouseState(&x, &y);
            std::cout << "X: " << x << " Y: " << y << std::endl;
        }
    }
}
