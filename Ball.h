#pragma once

#define MaxXSpeed    0.7

class Ball

{

private:

    static constexpr float _X_SPEED = 8;
    static constexpr float _Y_SPEED = 0.08;       

    Gamebuino_Meta::Color    color;

    void _ballMoveFree(float dt);
    void _ballTestRebound();
    void _ballTestReachBottom();
    void _ballFollowPaddle();


public:

    float       x, y;
    uint8_t     radius; 
    float       moveX, moveY;
    bool        bestroyed;
    bool        free;
    bool        metal;

    void ballCreateNew();
    void ballMove(float dt);
    void ballDraw();

    
};
