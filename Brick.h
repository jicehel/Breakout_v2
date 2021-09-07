#pragma once
#include "global.h"

#define NB_PTS_BRICK   10

extern Image imageBrique[12];

class Brick
{

private:


public:
  int8_t  typeBrick;
  bool    isHit;
  uint8_t x,y;
  uint8_t sizeX = 8;
  uint8_t sizeY = 4;

  void brickDraw(int8_t brickType, int8_t xBrique, int8_t yBrique);
  void brickCollisionDetected(int8_t r,int8_t c );
  void bounceY(int8_t r,int8_t c, bool bounced);
  void bounceX(int8_t r,int8_t c, bool bounced);
};
