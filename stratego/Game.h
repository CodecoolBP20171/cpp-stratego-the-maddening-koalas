//
// Created by alex on 2017.11.07..
//

#ifndef STRATEGO_GAME_H
#define STRATEGO_GAME_H

#include <iostream>
#include "engine/Engine.h"
#include "Board/GameBoard.h"
#include "Board/SideBoard.h"
#include "GameLogic/EventHandler.h"

class Game {
public:
    Game();
    ~Game() = default;
    void run();
    void init();

private:
    void preparePhase(bool& quit);
    void playerPhase(bool& quit);
    void reset();
    Engine engine;

    Scene scene;
    std::shared_ptr<GameBoard> gameBoard;
    std::shared_ptr<SideBoard> sideBoard;
    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;
    std::shared_ptr<NeutralPlayer> neutralPlayer;
    std::shared_ptr<EventHandler> eventHandler;
    std::shared_ptr<HighLight> highlight;
    Color currentPlayer;
    GameState gameState;
};

#endif //STRATEGO_GAME_H
