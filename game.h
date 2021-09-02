#pragma once

class Game
{

    private:

    #define NUM_HIGHSCORE     5
    #define NAMELENGTH        12
    #define NB_LEVEL          10

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

    //
    float _deltaTime;
    float _oldTime;
    int _highscore[NUM_HIGHSCORE];
    char _name[NUM_HIGHSCORE][NAMELENGTH+1];
   
    // Calculate DeltaTime
    float CalculateDeltaTime();

    void saveHighScore(unsigned int test_score);
    void initHighscore();
    
    public:
               
    // initialize game state (load all shaders/textures/levels)
    void init();
        
    // game loop
    void loop();
};
