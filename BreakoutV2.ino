//----------------------------------------------------------------------    
//                     Breakout v2 by Jicehel
//             
//----------------------------------------------------------------------    

#include <Gamebuino-Meta.h>
#include "Global.h"

// Objects
Game game;
Ball ball;
// Paddle paddle;
Levels level,

void setup() {
    gb.begin();
    gb.setFrameRate(60);
    game.init();
}

void loop() {
    gb.waitForUpdate();
    gb.display.clear();
    game.loop();
              SerialUSB.print(ball.radius);
              SerialUSB.print(":");
              SerialUSB.print(ball.x);
              SerialUSB.print(":");
              SerialUSB.print(ball.y);
              SerialUSB.print(":");
              SerialUSB.print(ball.moveX);
              SerialUSB.print(":");
              SerialUSB.print(ball.moveY);
              SerialUSB.println("");
}
