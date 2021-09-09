#pragma once

#define MaxXSpeed    0.5

class Ball

{

private:

    static constexpr float _X_SPEED = 6;
    static constexpr float _Y_SPEED = 0.06;       

    Gamebuino_Meta::Color    color;

    void _ballMoveFree(float dt);
    void _ballTestRebound();
    void _ballTestReachBottom();
    void _ballFollowPaddle();


public:

    static constexpr uint8_t ballSizeMini = 1;
    static constexpr uint8_t ballSizeMaxi = 2;    

    float       x, y;
    uint8_t     radius; 
    uint8_t     sizeX, sizeY;
    float       moveX, moveY;
    bool        bestroyed;
    bool        free;
    bool        metal;

    void ballCreateNew();
    void ballMove(float dt);
    void ballDraw();

    
};
