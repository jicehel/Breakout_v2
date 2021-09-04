#include <Gamebuino-Meta.h>

#include "Global.h"

// Ball images
    
uint16_t ball2Data[] = {2,2,1, 1, 0, 0, 0xffff,0xfb40,0xfb40,0x7980};
Image ball2 = Image(ball2Data);
uint16_t ball3Data[] = {3,3,1, 1, 0, 0, 0xffff,0xffff,0xfb40,0xffff,0xfec0,0x7980,0xfb40,0x7980,0x7980};
Image ball3 = Image(ball3Data);
uint16_t ball4Data[] = {4,4,1, 1, 0xf80d, 0, 0xf80d,0xffff,0xfb40,0xf80d,0xffff,0xfec0,0xfec0,0x7980,0xfb40,0xfec0,0xfb40,0x7980,0xf80d,0x7980,0x7980,0xf80d};
Image ball4 = Image(ball4Data);
uint16_t ball5Data[] = {5,5,1, 1, 0xf80d, 0, 0xf80d,0xfec0,0xffff,0x7800,0xf80d,0xfec0,0xffff,0xffff,0xfec0,0x7800,0xfec0,0xffff,0xfec0,0xfb40,0x7800,0x7800,0xfec0,0xfb40,0x7980,0x7800,0xf80d,0x7800,0x7800,0x7800,0xf80d};
Image ball5 = Image(ball5Data);
uint16_t ball4MetalData[] = {4,4,1, 1, 0xf80d, 0, 0xf80d,0xc618,0xad75,0xf80d,0xc618,0xef7d,0xdefb,0x3186,0xad75,0xdefb,0x630c,0x3186,0xf80d,0x3186,0x3186,0xf80d};
Image ball4Metal = Image(ball4MetalData);
    

void Ball::newBall (){
  // this -> free = false;
  this -> metal = false;
  this -> radius = 2;
  // y = paddle.py - balle.BSize;
  this -> y = HEIGHT /2 - this -> radius;
  // balle.x = paddle.px + midPaddle ;
  this -> x = WIDTH / 2 - this -> radius;

  // to test
  this -> free = true;
  this -> moveX  = 0.08;
  this -> moveY  = -0.08;
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
      if (game.sound) gb.sound.tone(523, 200);
      if (game.lightSides) { gb.lights.drawPixel(0, 0, YELLOW);gb.lights.drawPixel(1, 0, YELLOW); }
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
      if (game.sound) gb.sound.tone(523, 200);
      if (game.lightSides) { gb.lights.drawPixel(0, 0, YELLOW);gb.lights.drawPixel(0, 1, YELLOW);gb.lights.drawPixel(0, 2, YELLOW);gb.lights.drawPixel(0, 3, YELLOW); }
      delay(15);
    }
    //Bounce off right side
    if (this -> x > (WIDTH - 2 * this -> radius)) {
      this -> x = WIDTH - 2 * this -> radius;
      this -> moveX = -this -> moveX;
      if (game.sound)gb.sound.tone(523, 200);
      if (game.lightSides) { gb.lights.drawPixel(1, 0, YELLOW);gb.lights.drawPixel(1, 1, YELLOW);gb.lights.drawPixel(1, 2, YELLOW);gb.lights.drawPixel(1, 3, YELLOW); }
      delay(15);
    }

    if ((this -> y + 2* this -> radius) >= HEIGHT) {
      this -> y = HEIGHT - 2 * this -> radius;
      this -> moveY = - (this -> moveY);
      if (game.sound) gb.sound.tone(523, 200);
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
  if (game.lightSides) gb.lights.fill(BLACK);   
}

void Ball::drawBall() {
  gb.display.setColor(this -> color);
  if (!(this -> metal)) { 
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
