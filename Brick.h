#pragma once
#include "global.h"

extern Image imageBrique[12];

class Brick
{

private:
    static const uint8_t brickWidth =    8;
    static const uint8_t brickHeight =   4;
    static const uint8_t nbPointsBrick = 10;

public:
  int8_t  type_brick;
  bool    isHit;
  uint8_t x1,y1,x2,y2;

  void draw_brick(int8_t brickType, int8_t xBrique, int8_t yBrique);
  void collision_brick(int8_t r,int8_t c );
}
