//----------------------------------------------------------------------    
//                     Breakout v2 by Jicehel
//             
//----------------------------------------------------------------------    

#include <Gamebuino-Meta.h>
#include "Global.h"


// Objects
Game  game;
Ball  ball;
// Paddle paddle;
Brick  brick;
Levels level;
Paddle paddle;
Bonus bonus[20];

void setup() {
    game.init();
}

void loop() {
    gb.waitForUpdate();
    game.loop();
/*              
 *            Debug code example   
 *               
              SerialUSB.print(ball.radius);
              SerialUSB.print(":");
              SerialUSB.print(ball.x);
              SerialUSB.print(":");
              SerialUSB.print(ball.y);
              SerialUSB.print(":");
              SerialUSB.print(ball.moveX);
              SerialUSB.print(":");
              SerialUSB.print(ball.moveY);
              SerialUSB.println(""); */
}
