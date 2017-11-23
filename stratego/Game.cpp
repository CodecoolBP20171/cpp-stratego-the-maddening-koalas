//
// Created by alex on 2017.11.07..
//

#include "Game.h"

Game::Game(){
    sideBoard = std::make_shared<SideBoard>();

    highlight = std::make_shared<HighLight>();

    eventHandler = std::make_shared<EventHandler>(sideBoard, highlight);
}

void Game::init() {
    engine.init("Stratego", 750, 500);
    std::shared_ptr<Sprite> backround = std::make_shared<Sprite>(engine.getRenderer(), "images/strategobackground2.png");
    SDL_Rect bgrect = {0, 0, 750, 500};
    std::shared_ptr<Background> bg = std::make_shared<Background>(std::move(backround), bgrect);


    player1 = std::make_shared<Player>(Color::red, engine.getRenderer());
    player2 = std::make_shared<Player>(Color::blue, engine.getRenderer());
    neutralPlayer = std::make_shared<NeutralPlayer>(Color::neutral, engine.getRenderer());
    gameBoard = std::make_shared<GameBoard>(neutralPlayer);
    eventHandler->init(engine.getRenderer(), gameBoard);

    scene.addBackground(bg);
    scene.addNeutPlayer(neutralPlayer);
    
    currentPlayer = Color::red;
    gameState = GameState::setupPhase;
}

void Game::run() {
    SDL_Delay(100);

    bool quit = false;
    Uint32 timePassed = 0;
    Uint32 timestep = 16;

    while (!quit) {
        timePassed = SDL_GetTicks();
        SDL_RenderClear(engine.getRenderer());

        if(gameState == GameState::setupPhase){
            preparePhase(quit);
        } else if(gameState == GameState::gamePhase){
            playerPhase(quit);
        }

        scene.draw(engine.getRenderer(), highlight);

        SDL_RenderPresent(engine.getRenderer());

        while(timePassed + timestep > SDL_GetTicks()) {
            SDL_Delay(0);
        }
    }

}

void Game::preparePhase(bool& quit) {
    // This part adding the cards to thi scene.
    if(!sideBoard->isSet()){
        if(currentPlayer == Color::red){
            gameBoard->init(player1);
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

