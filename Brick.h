#pragma once
#include "global.h"

#define BRICK_WIDTH      8
#define BRICK_HEIGHT     4
#define NB_PTS_BRICK   10

extern Image imageBrique[12];

class Brick
{

private:


public:
  int8_t  typeBrick;
  bool    isHit;
  uint8_t x1,y1,x2,y2;

  void drawBrick(int8_t brickType, int8_t xBrique, int8_t yBrique);
  void collision_brick(int8_t r,int8_t c );
};
