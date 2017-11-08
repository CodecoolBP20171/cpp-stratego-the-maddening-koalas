#include <iostream>
#include "engine/Engine.h"
#include "Card.h"

int main() {
    Engine engine;

    engine.init("Stratego", 800, 600);
    Scene scene;

    for (int y = 0; y < 500; y += 50) {
        for (int x = 0; x < 500; x += 50) {
            Card card(engine.getRenderer(), "images/bomb.png", 50, 50, x, y, x+y);
            scene.addObject(card);
        }
    }



    // wait a little so the animation won't start before the window appears
    SDL_Delay(100);

    bool quit = false;
    Uint32 timePassed = 0;
    Uint32 timestep = 16;

    while (!quit) {
        timePassed = SDL_GetTicks();

        SDL_Event e;
        while( SDL_PollEvent( &e ) != 0 ) // poll for events received from user or operating system
        {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }

            scene.draw(engine.getRenderer());

            while(timePassed + timestep > SDL_GetTicks()){
                SDL_Delay(0);
            }
        }
    }

    return 0;
}