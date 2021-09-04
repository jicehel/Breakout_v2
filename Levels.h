#pragma once
#include "Brick.h"

#define NbLevels 10
#define NbRows    5
#define NbCol    10

extern int8_t level_brick[NbLevels][NbRows * NbCol + 1];
extern Brick currentLevel[NbRows][NbCol];

class Levels
{

private:

    static const uint8_t _COLUMNS   = NbCol;        // Columns of bricks
    static const uint8_t _ROWS      = NbRows;       // Rows of bricks
    static const uint8_t _NUM_LEVEL = NbLevels;     // Number of created levels


public:

    uint8_t brickCount, nbBricks, nbBonus, defaultBonusBrick;

    void resetCurrentLevel();
    uint8_t checkEndLevel();
    void checkLevelEvent();

}