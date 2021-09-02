#include <Gamebuino-Meta.h>
#include "Game.h"

void Game::init() {
    _state   = GameState::TITLESCREEN;
    _oldTime = 0;
}

// Calculate DeltaTime
float Game::CalculateDeltaTime(){
    float currentTime = millis();
    float deltaTime = currentTime - _oldTime;
    _oldTime = currentTime;
    return deltaTime;
}


// Load High scores
void Game::initHighscore(){
  for(byte thisScore = 0; thisScore < NUM_HIGHSCORE; thisScore++){
    _highscore[thisScore] = gb.save.get(2*thisScore);
    gb.save.get(2*thisScore + 1, _name[thisScore], NAMELENGTH+1);
  }
}


// Save HighScore
void Game::saveHighScore(unsigned int test_score) {

    if (test_score > _highscore[NUM_HIGHSCORE-1]){  //if it's a highscore
          gb.getDefaultName(_name[NUM_HIGHSCORE-1]);
          gb.gui.keyboard("Name", _name[NUM_HIGHSCORE-1]);
          _highscore[NUM_HIGHSCORE-1] = test_score;
          for(byte i=NUM_HIGHSCORE-1; i>0; i--){ //bubble sorting FTW
              if(_highscore[i-1] < _highscore[i]){
                  char tempName[NAMELENGTH];
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
          
          for(byte thisScore = 0; thisScore < NUM_HIGHSCORE; thisScore++){
              gb.save.set(2*thisScore, _highscore[thisScore]);
              gb.save.set(2*thisScore + 1, _name[thisScore]);
          }
    } // end of highscore test part
}



void Game::loop() {

    _deltaTime = CalculateDeltaTime();
  
    switch (_state) {
      
      case GameState::TITLESCREEN:
      break;

      case GameState::RUNNING:
      break;

      case GameState::PAUSE:
      break;

      case GameState::GAMEOVER:
      break;
      
    }
}
