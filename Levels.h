#pragma once

#define NB_LEVELS  10
#define NB_ROWS    5
#define NB_COLUMNS 10

class Levels
{

private:



public:

    static const uint8_t _COLUMNS   = NB_COLUMNS;        // Columns of bricks
    static const uint8_t _ROWS      = NB_ROWS;       // Rows of bricks
    static const uint8_t _NUM_LEVEL = NB_LEVELS;     // Number of created levels

    uint8_t levelBrickCount, levelNbBricks, levelDefaultBonusBrick;

    void    reset();
    uint8_t checkEnd();
    void    checkEvent();
    void    draw();

};
