#pragma once

#ifndef GLOBAL_DATA
#define GLOBAL_DATA

#include "Game.h"
#include "Ball.h"
#include "Assets.h"

// constantes
static const uint8_t  WIDTH  = gb.display.width();
static const uint8_t  HEIGHT = gb.display.height();
static const uint8_t  YTOP   = 12;

// Objects
Game game;
Ball ball;
// Paddle paddle;

#endif
