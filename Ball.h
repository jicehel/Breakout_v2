#pragma once

extern Image ball2, ball3, ball4, ball5, ball4Metal;


class Ball

{

private:

    // object state
    
    Gamebuino_Meta::Color    color;
    bool        bestroyed;
    bool        free;
    bool        metal;


public:

    float       x, y;
    uint8_t     radius; 
    float       moveX, moveY;

    void newBall();
    void moveBall(float dt);
    void drawBall();

    
};
