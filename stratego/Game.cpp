//
// Created by alex on 2017.11.07..
//

#include "Game.h"

void Game::init() {
    engine.init("Stratego", 800, 600);
    std::shared_ptr<Sprite> backround = std::make_shared<Sprite>(engine.getRenderer(), "images/strategobackground.png");
    SDL_Rect bgrect = {0, 0, 800, 600};
    std::shared_ptr<Background> bg = std::make_shared<Background>(std::move(backround), bgrect);
    scene.addBackground(bg);

}

void Game::run() {
    preparePhase();

}

void Game::preparePhase() {
    std::shared_ptr<Player> player1 = std::make_shared<Player>("red", engine.getRenderer());

    scene.addPlayer(player1);

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
}
