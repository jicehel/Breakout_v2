#pragma once

class Game
{

private:

    static const uint8_t _NUM_HIGHSCORE = 5;       // Number of highscores to keep
    static const uint8_t _NAME_LENGTH   = 12;      // Lenght of names kept in Highscores
    static const uint8_t _NUM_LEVEL     = 10;      // Number of created levels

    float_t _calculateDeltaTime();
    void    _saveHighScore(unsigned int test_score);
    void    _initHighScore();

    
    // Represents the current state of the game

    enum class GameState : uint8_t {
            
            TITLESCREEN,
            RUNNING,
            PAUSE,
            GAMEOVER
            
    };

    // game state
    GameState    _state;  

    float _deltaTime;
    float _oldTime;
    int _highscore[_NUM_HIGHSCORE];
    char _name[_NUM_HIGHSCORE][_NAME_LENGTH+1];


    
public:

    static const boolean lightSides = true;
               
    // initialize game state (load all shaders/textures/levels)
    void init();
        
    // game loop
    void loop();
    
};
