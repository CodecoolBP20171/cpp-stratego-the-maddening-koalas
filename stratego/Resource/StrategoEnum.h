//
// Created by alex on 2017.11.21..
//

#ifndef STRATEGO_STRATEGOENUM_H
#define STRATEGO_STRATEGOENUM_H
namespace BoardInfo {
    const unsigned sideBoardStartX = 505;
    const unsigned sideBoardEndX = 745;
    const unsigned sideBoardStartY = 111;
    const unsigned sideBoardEndY = 495;

    const unsigned GameBoardStartX = 6;
    const unsigned GameBoardEndX = 495;
    const unsigned GameBoardStartY = 5;
    const unsigned GameBoardEndY = 495;

    const unsigned cardWidth = 48;
    const unsigned cardHeigth = 48;
}

enum Color {
    red,
    blue,
    neutral
};

enum GameState {
    setupPhase,
    gamePhase
};

enum SpriteName {
    FLAG,
    SPY,
    SCOUT,
    MINER,
    SERGEANT,
    LIEUTENANT,
    CAPTAIN,
    MAJOR,
    COLONEL,
    GENERAL,
    MARSHALL,
    BOMB,
    BACK,
    PLACEHOLDER,
    EMPTY,
    WATER
};

enum NeutralName {
    PHOLDER,
    EMP,
    WAT
};

#endif //STRATEGO_STRATEGOENUM_H
