#include <Gamebuino-Meta.h>
#include "Global.h"

void Game::init() {
    _state   = GameState::TITLESCREEN;
    _oldTime = 0;
}

// Calculate DeltaTime
float_t Game::_calculateDeltaTime(){
    float currentTime = millis();
    float deltaTime = currentTime - _oldTime;
    _oldTime = currentTime;
    return deltaTime;
}


// Load High scores
void Game::_initHighScore(){
  for(byte thisScore = 0; thisScore < _NUM_HIGHSCORE; thisScore++){
    _highscore[thisScore] = gb.save.get(2*thisScore);
    gb.save.get(2*thisScore + 1, _name[thisScore], _NAME_LENGTH+1);
  }
}


// Save HighScore
void Game::_saveHighScore(unsigned int test_score) {

    if (test_score > _highscore[_NUM_HIGHSCORE-1]){  //if it's a highscore
          gb.getDefaultName(_name[_NUM_HIGHSCORE-1]);
          gb.gui.keyboard("Name", _name[_NUM_HIGHSCORE-1]);
          _highscore[_NUM_HIGHSCORE-1] = test_score;
          for(byte i= _NUM_HIGHSCORE-1; i>0; i--){ //bubble sorting FTW
              if(_highscore[i-1] < _highscore[i]){
                  char tempName[_NAME_LENGTH];
                  strcpy(tempName, _name[i-1]);
                  strcpy(_name[i-1], _name[i]);
                  strcpy(_name[i], tempName);
                  unsigned int tempScore;
                  tempScore = _highscore[i-1];
                  _highscore[i-1] = _highscore[i];
                  _highscore[i] = tempScore;
              } else {
                  break;
              }
          }
          
          for(byte thisScore = 0; thisScore < _NUM_HIGHSCORE; thisScore++){
              gb.save.set(2*thisScore, _highscore[thisScore]);
              gb.save.set(2*thisScore + 1, _name[thisScore]);
          }
    } // end of highscore test part
}



void Game::loop() {

    _deltaTime = _calculateDeltaTime();
  
    switch (_state) {
      
      case GameState::TITLESCREEN:
          ball.newBall();
          GameState::RUNNING;
      break;

      case GameState::RUNNING:
          ball.moveBall(_deltaTime);
          ball.drawBall();
      break;

      case GameState::PAUSE:
      break;

      case GameState::GAMEOVER:
      break;
      
    }
}
