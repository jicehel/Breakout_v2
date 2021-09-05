#pragma once

class Paddle


{

private:

    static const uint8_t     _paddleDefaulSize = 16;
    static const uint8_t     _yPaddle    =       62;
    static const uint8_t     _paddlewidthmin =   4;
    static const uint8_t     _paddlewidthmax =   30;


public:

    int8_t      x;
    uint8_t     y;
    uint8_t     pWidth, pHeight;
    int8_t      pSpeed;
    uint8_t     nbGlue;
    boolean     glue;

    void paddleReset();
    void paddleMove();
    void paddleDraw();

    
};
