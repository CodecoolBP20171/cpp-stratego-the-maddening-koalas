#include <iostream>
#include "engine/Engine.h"
#include "Game.h"

int main() {
    Game game;
    game.init();
    game.run();
    // Init engine
/*
    std::shared_ptr<Player> player1 = std::make_shared<Player>("red", engine.getRenderer());
    std::shared_ptr<Player> player2 = std::make_shared<Player>("blue", engine.getRenderer());

    scene.addPlayer(player1);
    scene.addPlayer(player2);
    // wait a little so the animation won't start before the window appears
    SDL_Delay(100);

    bool quit = false;
    Uint32 timePassed = 0;
    Uint32 timestep = 16;

    while (!quit) {
        timePassed = SDL_GetTicks();

        SDL_Event e;
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        scene.draw(engine.getRenderer());

        while(timePassed + timestep > SDL_GetTicks()) {
            SDL_Delay(0);
        }
    }
*/
    return 0;
}