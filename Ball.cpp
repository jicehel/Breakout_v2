#include <Gamebuino-Meta.h>
#include "Global.h"

// Ball images
    
const uint16_t ball2Data[] = {2,2,1, 1, 0, 0, 0xffff,0xfb40,0xfb40,0x7980};
Image ball2 = Image(ball2Data);
const uint16_t ball3Data[] = {3,3,1, 1, 0, 0, 0xffff,0xffff,0xfb40,0xffff,0xfec0,0x7980,0xfb40,0x7980,0x7980};
Image ball3 = Image(ball3Data);
const uint16_t ball4Data[] = {4,4,1, 1, 0xf80d, 0, 0xf80d,0xffff,0xfb40,0xf80d,0xffff,0xfec0,0xfec0,0x7980,0xfb40,0xfec0,0xfb40,0x7980,0xf80d,0x7980,0x7980,0xf80d};
Image ball4 = Image(ball4Data);
const uint16_t ball5Data[] = {5,5,1, 1, 0xf80d, 0, 0xf80d,0xfec0,0xffff,0x7800,0xf80d,0xfec0,0xffff,0xffff,0xfec0,0x7800,0xfec0,0xffff,0xfec0,0xfb40,0x7800,0x7800,0xfec0,0xfb40,0x7980,0x7800,0xf80d,0x7800,0x7800,0x7800,0xf80d};
Image ball5 = Image(ball5Data);
const uint16_t ball4MetalData[] = {4,4,1, 1, 0xf80d, 0, 0xf80d,0xc618,0xad75,0xf80d,0xc618,0xef7d,0xdefb,0x3186,0xad75,0xdefb,0x630c,0x3186,0xf80d,0x3186,0x3186,0xf80d};
Image ball4Metal = Image(ball4MetalData);
    

void Ball::ballCreateNew (){
  this -> free = false;
  // this -> free = true;
  this -> metal = false;
  this -> radius = 2;
  this -> y = paddle.y - 2 * this -> radius;
  this -> x = paddle.x + paddle.pWidth / 2 - ball.radius ;
  this -> color  = YELLOW;
  
  // value to make tests
  // this -> moveX  = 0.08;
  // this -> moveY  = -0.08;
  
}

void Ball::ballMove(float dt) {
    if (this -> free) {
      Ball::_ballMoveFree(dt);
      Ball::_ballTestRebound();
      Ball::_ballTestReachBottom();
    } else {
      Ball::_ballFollowPaddle();
    }
    if (game.lightSides) gb.lights.fill(BLACK);   
}


void Ball::_ballTestRebound() {
    //Bounce off top edge
    if (this -> y <= YTOP) {
      this -> y = YTOP;
      this -> moveY = - this -> moveY;
      if (game.sound) gb.sound.tone(523, 200);
      if (game.lightSides) { gb.lights.drawPixel(0, 0, YELLOW);gb.lights.drawPixel(1, 0, YELLOW); }
      delay(15);
    }
    
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
    
    //Bounce on paddle  
    if (((this -> x + 2 * this -> radius) >= paddle.x) && (this -> x <= paddle.x + paddle.pWidth) && ((this -> y + 2 * this -> radius) >= paddle.y) && (this -> y <= paddle.y + paddle.pHeight)) {
      if (paddle.glue==false) {
        if (this -> moveY > 0) {
          this -> moveY = -this -> moveY;
          this -> moveX = this -> moveX  - (paddle.x + paddle.pWidth / 2 - ball.radius - this -> x + random(-_X_SPEED, _X_SPEED)) / 200; //Applies spin on the ball
        }
        //limit horizontal speed
        if (this -> moveX < -MaxXSpeed)  this -> moveX = -MaxXSpeed;
        if (this -> moveX >  MaxXSpeed)  this -> moveX =  MaxXSpeed;
        if (game.sound) gb.sound.tone(200, 200);
        if (game.lightSides) { gb.lights.drawPixel(0, 3, YELLOW);gb.lights.drawPixel(1, 3, YELLOW); }
        delay(2);
      } else this -> free = false;  
   }
}

void Ball::_ballTestReachBottom() {
  //Lose a life if bottom edge hit
  if (this -> y > paddle.y - this -> radius + 0.5 * paddle.pHeight) {
      // gb.sound.play("LoseALife.wav");
      if (game.lightSides)gb.lights.fill(RED);
      // if (game.sound) gb.sound.fx(LoseLife);
      delay(300);
      this -> y = paddle.y - 2 * this -> radius;
      this -> free = false;
      game.lives = game.lives - 1;
      level.levelNbBonus = 0;
      this -> metal = false;
      paddle.glue =false;
    } 
}


void Ball::_ballMoveFree(float dt) {
    this -> x += this -> moveX * dt;
    this -> y += this -> moveY * dt;
}
    
 
void Ball::_ballFollowPaddle() {
    this -> x = paddle.x + (paddle.pWidth - 2*ball.radius)/2 ;
    this -> y = paddle.y - 2 * this -> radius;
    //Release ball if FIRE pressed
    if (gb.buttons.pressed(BUTTON_A)) {
      this -> free = true;
      if (paddle.nbGlue > 0) paddle.nbGlue--;
      if (paddle.nbGlue <= 0) paddle.glue = false;
      // if (gb.buttons.pressed(BUTTON_LEFT) || gb.buttons.pressed(BUTTON_RIGHT)) {
        // if (gb.buttons.pressed(BUTTON_LEFT)) this -> moveX = 0.5;
        // else this -> moveX = -0.5;
      // } else this -> moveX = random(-1, 1) / 2;
      this -> moveX = (random(2 * this ->_X_SPEED)- this ->_X_SPEED) / 200;
      this -> moveY = -_Y_SPEED;
    }     
}

void Ball::ballDraw() {
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
