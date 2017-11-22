//
// Created by alex on 2017.11.07..
//

#include "Game.h"
#include "HighLight.h"


Game::Game() {
    gameBoard = std::make_shared<GameBoard>();
    sideBoard = std::make_shared<SideBoard>();
}


void Game::init() {
    engine.init("Stratego", 750, 500);
    std::shared_ptr<Sprite> backround = std::make_shared<Sprite>(engine.getRenderer(), "images/strategobackground.png");
    SDL_Rect bgrect = {0, 0, 750, 500};
    std::shared_ptr<Background> bg = std::make_shared<Background>(std::move(backround), bgrect);
    scene.addBackground(bg);
    eventHandler.init(engine.getRenderer());
}

void Game::run() {
    preparePhase();

}

void Game::preparePhase() {
    std::shared_ptr<Player> player1 = std::make_shared<Player>("blue", engine.getRenderer());
    sideBoard->setPlayerCards(player1);
    scene.addPlayer(player1);

    SDL_Delay(100);

    bool quit = false;
    Uint32 timePassed = 0;
    Uint32 timestep = 16;
    while (!quit) {
        timePassed = SDL_GetTicks();

        SDL_RenderClear(engine.getRenderer());

        scene.draw(engine.getRenderer(), eventHandler);
        eventHandler.handleEvent(quit, sideBoard, engine.getRenderer());

        SDL_RenderPresent(engine.getRenderer());

        while(timePassed + timestep > SDL_GetTicks()) {
            SDL_Delay(0);
        }
    }
}

