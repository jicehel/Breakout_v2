#pragma once

class Game
{

private:

    static const uint8_t _NUM_HIGHSCORE = 5;       // Number of highscores to keep
    static const uint8_t _NAME_LENGTH   = 12;      // Lenght of names kept in Highscores

    float_t _calculateDeltaTime();
    void    _saveHighScore(unsigned int test_score);
    void    _initHighScore();
    void    _newGame();
    void    _pause();
    void    _showTitleScreen();
    void    _initTitleScreen();
    void    _checkLives();
    void    _checkBrickCollision();
    void    _showControls();
    void    _showOptions();
    bool    _checkCollision(int8_t obj1_x, int8_t obj1_y,uint8_t obj1_sizeX,uint8_t obj1_sizeY,int8_t obj2_x, int8_t obj2_y,uint8_t obj2_sizeX,uint8_t obj2_sizeY );

    
    // Represents the current state of the game

    enum class GameState : uint8_t {
            
            TITLESCREEN,
            RUNNING,
            SHOW_CONTROLS,
            SHOW_MORE_OPTIONS,
            SHOW_SCORES,
            SHOW_CREDITS,
            SHOW_OPTIONS,
            PAUSE,
            GAMEOVER,
            RESTART
    };

    // game state
    GameState    _state;  

    float   _deltaTime;
    float   _oldTime;
    int     _highscore[_NUM_HIGHSCORE];
    char    _name[_NUM_HIGHSCORE][_NAME_LENGTH+1];
    uint8_t _animStartMenu;
    uint8_t _dirAnimMenu;
    bool    _initOptions;
    uint8_t _currentSelectedOption;
    float   _frameCount;
    float   _frameStart;


    
public:

    boolean   sound, lightSides;
    uint16_t  score;
    uint8_t   currentLevelNb, bonusNb, lives;
               
    void init();
    void showInfos();

    void loop();
    
};
