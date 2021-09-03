#pragma once

#include "Game.h"
#include "Ball.h"

// constantes
static const uint8_t  WIDTH  = gb.display.width();
static const uint8_t  HEIGHT = gb.display.height();
static const uint8_t  YTOP   = 12;

// Objects
extern Game game;
extern Ball ball;
// extern Paddle paddle;
