#pragma once

#ifndef BALL_CLASS
#define BALL_CLASS

class Ball

{

private:

    // object state
    
    uint8_t     x, y;
    uint8_t     radius, moveX, moveY;
    Gamebuino_Meta::Color    color;
    bool        bestroyed;
    bool        free;
    bool        metal;


public:

    void newBall();
    void moveBall(float dt);
    void drawBall();

    
};

#endif
