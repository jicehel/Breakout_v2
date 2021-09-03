#include <Gamebuino-Meta.h>

#include "Global.h"

void Ball::newBall (){
  // this -> free = false;
  this -> metal = false;
  this -> radius = 2;
  // y = paddle.py - balle.BSize;
  y = HEIGHT - 2 * radius;
  // balle.x = paddle.px + midPaddle ;
  x = WIDTH / 2 - radius;

  // to test
  this -> free = true;
  this -> moveX  = 2;
  this -> moveY  = 2;
  this -> color  = YELLOW;
}


void Ball::moveBall(float dt) {
  // SerialUSB.println("Do Ball");
  if (this -> free) {
    //Move ball
    this -> x += this -> moveX * dt;
    this -> y += this -> moveY * dt;
    //Bounce off top edge
    if (this -> y <= YTOP) {
      this -> y = YTOP;
      this -> moveY = - this -> moveY;
      gb.sound.tone(523, 200);
      //if (game.lightSides) { gb.lights.drawPixel(0, 0, YELLOW);gb.lights.drawPixel(1, 0, YELLOW); }
      delay(15);
    }
  }
    /* 
    //Lose a life if bottom edge hit
    if (y > paddle.py - radius + 0.5*paddle.pheight) {
      // gb.sound.play("LoseALife.wav");
      gb.lights.fill(RED);
      gb.sound.fx(LoseLife);
      delay(300);
      balle.y = paddle.py - balle.BSize;
      balle.Free = false;
      lives = lives - 1;
      Nb_bonus = 0;
      metal = false;
      glue =false;
    } */
    //Bounce off left side
    if (this -> x < 1) {
      this -> x = 1;
      this -> moveX = -this -> moveX;
      gb.sound.tone(523, 200);
      // if (game.lightSides) { gb.lights.drawPixel(0, 0, YELLOW);gb.lights.drawPixel(0, 1, YELLOW);gb.lights.drawPixel(0, 2, YELLOW);gb.lights.drawPixel(0, 3, YELLOW); }
      delay(15);
    }
    //Bounce off right side
    if (this -> x > (WIDTH - 2 * this -> radius)) {
      this -> x = WIDTH - 2 * this -> radius;
      this -> moveX = -this -> moveX;
      gb.sound.tone(523, 200);
      // if (game.lightSides) { gb.lights.drawPixel(1, 0, YELLOW);gb.lights.drawPixel(1, 1, YELLOW);gb.lights.drawPixel(1, 2, YELLOW);gb.lights.drawPixel(1, 3, YELLOW); }
      delay(15);
    }

    if ((this -> y + 2* this -> radius) >= HEIGHT) {
      this -> y = HEIGHT - 2 * this -> radius;
      this -> moveY = - (this -> moveY);
      gb.sound.tone(523, 200);
      delay(15); 
    }

    //Reset Bounce
    /*     
      //Bounce off paddle
      
      if (((balle.x + balle.BSize) >= paddle.px) && (balle.x <= paddle.px + paddle.pwidth) && ((balle.y + balle.BSize) >= paddle.py) && (balle.y <= paddle.py + paddle.pheight)) {
      if (glue==false) {
        if (balle.moveY > 0) {
          balle.moveY = -balle.moveY;
          balle.moveX = balle.moveX  - (paddle.px + midPaddle - balle.x + random(-1, 1)) / 4; //Applies spin on the ball
        }
        //limit horizontal speed
        if (balle.moveX < -MaxXSpeed) balle.moveX = -MaxXSpeed;
        if (balle.moveX > MaxXSpeed)  balle.moveX =  MaxXSpeed;
        gb.sound.tone(200, 200);
        if (LightSides) { gb.lights.drawPixel(0, 3, YELLOW);gb.lights.drawPixel(1, 3, YELLOW); }
        delay(2);
      } else balle.Free = false;  
    } // end bounce off paddle

    bounced = false;
  } // End of Ball free
    else {
    //Ball follows paddle (not free) 
    balle.x = paddle.px + midPaddle ;
    balle.y = paddle.py - balle.BSize;
    //Release ball if FIRE pressed
    if (gb.buttons.pressed(BUTTON_A)) {
      balle.Free = true;
      if (Nb_glue > 0) Nb_glue--;
      if (Nb_glue <= 0) glue = false;
      if (gb.buttons.pressed(BUTTON_LEFT) || gb.buttons.pressed(BUTTON_RIGHT)) {
        if (gb.buttons.pressed(BUTTON_LEFT)) balle.moveX = 0.5;
        else balle.moveX = -0.5;
      } else balle.moveX = random(-1, 1) / 2;
      balle.moveY = -1;
    } 
  } */       
}

void Ball::drawBall() {
  gb.display.setColor(this -> color);
  if (! this -> metal) {
      switch (this -> radius) {
           case 1 : 
              gb.display.drawImage(this -> x, this -> y, ball2);
           break;
           case 2 : 
              gb.display.drawImage(this -> x, this -> y, ball4);
           break; 
       } // end Switch
  } else  gb.display.drawImage(this -> x, this -> y, ball4Metal);          
}
