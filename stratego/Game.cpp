//
// Created by alex on 2017.11.07..
//

#include "Game.h"


Game::Game(){
    gameBoard = std::make_shared<GameBoard>();
    sideBoard = std::make_shared<SideBoard>();
    mouseClick = std::make_shared<MouseClick>();
    eventHandler = std::make_shared<EventHandler>(mouseClick, sideBoard);
}


void Game::init() {
    engine.init("Stratego", 750, 500);
    std::shared_ptr<Sprite> backround = std::make_shared<Sprite>(engine.getRenderer(), "images/strategobackground.png");
    SDL_Rect bgrect = {0, 0, 750, 500};
    std::shared_ptr<Background> bg = std::make_shared<Background>(std::move(backround), bgrect);
    scene.addBackground(bg);

    player1 = std::make_shared<Player>("red", engine.getRenderer());
    player2 = std::make_shared<Player>("blue", engine.getRenderer());

    currentPlayer = Color::red;
    gameState = GameState::setupPhase;
}

void Game::run() {
//    preparePhase();

    SDL_Delay(100);

    bool quit = false;
    Uint32 timePassed = 0;
    Uint32 timestep = 16;
//    SDL_Event e;
    while (!quit) {
        timePassed = SDL_GetTicks();

        if(gameState == GameState::setupPhase){
            preparePhase(quit);
        } else if(gameState == GameState::gamePhase){
            playerPhase(quit);
        }

        scene.draw(engine.getRenderer());

        while(timePassed + timestep > SDL_GetTicks()) {
            SDL_Delay(0);
        }
    }

}

void Game::preparePhase(bool& quit) {
    // This part adding the cards to thi scene.
    if(!sideBoard->isSet()){
        if(currentPlayer == Color::red){
            sideBoard->setPlayerCards(player1);
            scene.addPlayer(player1);
            sideBoard->doneSet();
        } else {
            sideBoard->setPlayerCards(player2);
            scene.addPlayer(player2);
            sideBoard->doneSet();
        }
    }
    // If every sideBoard is empty reset side bord set and switch color!!!
    eventHandler->handleEvent(quit, currentPlayer, gameState);
}

void Game::playerPhase(bool& quit) {
    eventHandler->handleEvent(quit, currentPlayer, gameState);
}

