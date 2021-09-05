#pragma once

#include "Game.h"
#include "Sounds.h"
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"
#include "Bonus.h"
#include "Levels.h"


// Constantes
#define WIDTH  80
#define HEIGHT 64
#define YTOP   12

// Objects
extern Game game;
extern Ball ball;
// extern Paddle paddle;
extern Brick brick;
extern Levels level;
extern Paddle paddle;

extern Brick currentLevel[Levels::_ROWS][Levels::_COLUMNS];
