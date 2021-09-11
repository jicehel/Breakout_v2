#include <Gamebuino-Meta.h>
#include "Global.h"

const uint16_t paddleLeftSideData[] = {2,2,1, 1, 0, 0, 0x7980,0xfb40,0x7800,0x7980};  //  brown, orange and dark brown, brown 
Image paddleLeftSide = Image(paddleLeftSideData);

const uint16_t paddleRightSideData[] = {2,2,1, 1, 0, 0, 0xfb40,0x7980,0x7980,0x7800};  // orange, brown and braon, dark drown
Image paddleRightSide = Image(paddleRightSideData);


void Paddle::paddleReset() {
  this -> sizeX = this -> _paddleDefaulSize;
  this -> x = (WIDTH - this -> sizeX)/2;
  this -> y = this -> _yPaddle;
  this -> glue = false;
  this -> pSpeed = 3;
}


void Paddle::paddleMove() {
  if (this -> x < (WIDTH - this -> sizeX)) 
    if (gb.buttons.repeat(BUTTON_RIGHT,0)) this -> x = this -> x + this -> pSpeed;
  if (this -> x > 0) 
    if (gb.buttons.repeat(BUTTON_LEFT,0)) this -> x = this -> x - this -> pSpeed;
  if (this -> x < 1) this -> x = 0;
  if (this -> x > WIDTH - this -> sizeX) this -> x = WIDTH - this -> sizeX;
}


void Paddle::paddleDraw() {
  if (this -> glue == 0) {
     gb.display.setColor(WHITE);
  } else {
     gb.display.setColor(LIGHTGREEN);
  }
  gb.display.drawLine( this -> x + 2 , this -> y , this -> x + this -> sizeX - 2 , this -> y );
  gb.display.setColor(GRAY);
  gb.display.drawLine( this -> x + 2 , this -> y + 1 , this -> x + this -> sizeX - 2 , this -> y +1 );
  gb.display.drawImage(this -> x, this -> y, paddleLeftSide);
  gb.display.drawImage(this -> x + this -> sizeX - 2, this -> y, paddleRightSide);
}
