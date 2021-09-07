#pragma once
#include "global.h"

#define NB_DEF_GLUE       20

class Bonus
{

private:

    static const uint8_t _bonusSpeed       =   2;
    static const uint8_t _bonusMultiplier  =   3;

    void _bonusCheckCollision(uint8_t i);
    void _bonusClear(uint8_t i);



public:

    uint8_t x,y;
    uint8_t bType;
    uint8_t sizeX  =   7;
    uint8_t sizeY  =   4;

    void bonusMove();
    void bonusDraw();
    void bonusAdd(uint8_t bType,uint8_t bx,uint8_t by);

};
