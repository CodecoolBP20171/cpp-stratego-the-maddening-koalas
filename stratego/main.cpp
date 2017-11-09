#include <iostream>
#include "engine/Engine.h"
#include "Card.h"

int main() {
    Engine engine;

    engine.init("Stratego", 800, 600);
    Scene scene;

    Sprite* texture = new Sprite(engine.getRenderer(), "images/bomb.png");
    SDL_Rect rect{0, 0, 100, 100};
    Card card(texture, rect, 11);

    scene.addObject(card);


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