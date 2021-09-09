#pragma once

class Paddle


{

private:

    static const uint8_t     _paddleDefaulSize = 18;
    static const uint8_t     _yPaddle    =       62;



public:

    static const uint8_t     paddleWidthMin =   4;
    static const uint8_t     paddleWidthMax =   30;

    int8_t      x;
    uint8_t     y;
    uint8_t     sizeX, sizeY;
    int8_t      pSpeed;
    uint8_t     nbGlue;
    boolean     glue;

    void paddleReset();
    void paddleMove();
    void paddleDraw();

    
};
