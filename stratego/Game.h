//
// Created by alex on 2017.11.07..
//

#ifndef STRATEGO_GAME_H
#define STRATEGO_GAME_H

#include <iostream>
#include "engine/Engine.h"
#include "GameBoard.h"
#include "SideBoard.h"

class Game {
public:
    Game() = default;
    ~Game() = default;
    void run();
    void init();

private:
    void preparePhase();
    void playerPhase();
    void reset();

    Engine engine;
    Scene scene;
    std::unique_ptr<GameBoard> gameBoard;
    std::unique_ptr<SideBoard> sideBoard;
private:

};

//-init(): void // set instances default position
//+run(): void // preparePhase and playerPhase
//-generate(): void // static element and instance
//-preparePhase(): void
//-playerPhase(): void
//-reset(): void // will call init and prepare()

#endif //STRATEGO_GAME_H
