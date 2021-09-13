#pragma once
#include "global.h"

#define NB_DEF_GLUE       20

class Bonus
{

private:

    static constexpr float _bonusSpeed       =   0.05;
//    static const uint8_t _bonusMultiplier  =   3;

    void _checkCollision(uint8_t i);
    void _clear(uint8_t i);



public:

    float x,y;
    uint8_t bType;
    uint8_t sizeX  =   7;
    uint8_t sizeY  =   5;

    void move(float dt);
    void draw();
    void initNew(uint8_t bType,uint8_t bx,uint8_t by);

};
