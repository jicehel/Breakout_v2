#pragma once

class Game
{

    private:

    // Represents the current state of the game

    enum class GameState : uint8_t {
            
            TITLESCREEN,
            RUNNING,
            PAUSE,
            GAMEOVER
            
    };

    // game state
    GameState    _state;  

    // constantes
    uint8_t Width  = gb.display.width();
    uint8_t Height = gb.display.height();


    
    public:
               
    // initialize game state (load all shaders/textures/levels)
    void Init();
        
    // game loop
    void Loop();
};
