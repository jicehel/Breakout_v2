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
    void    _showTitlescreen();

    
    // Represents the current state of the game

    enum class GameState : uint8_t {
            
            TITLESCREEN,
            RUNNING,
            PAUSE,
            GAMEOVER
            
    };

    // game state
    GameState    _state;  

    float   _deltaTime;
    float   _oldTime;
    int     _highscore[_NUM_HIGHSCORE];
    char    _name[_NUM_HIGHSCORE][_NAME_LENGTH+1];
    uint8_t _animStartMenu;
    uint8_t _dirAnimMenu;


    
public:

    boolean   sound, lightSides;
    uint16_t  score;
    uint8_t   currentLevelNb, lives;
               
    void init();
    void showInfos();
    void checkLives();
    void loop();
    
};
