#pragma once

#include "Game.h"
#include "Ball.h"
#include "Levels.h"
#include "Brick.h"

// Constantes
static const uint8_t  WIDTH  = gb.display.width();
static const uint8_t  HEIGHT = gb.display.height();
static const uint8_t  YTOP   = 12;

// Objects
extern Game game;
extern Ball ball;
// extern Paddle paddle;
extern Levels level,


// Sounds
extern Gamebuino_Meta::Sound_FX loseLife[];
extern Gamebuino_Meta::Sound_FX SLostlife[];
extern Gamebuino_Meta::Sound_FX SBonus[];
