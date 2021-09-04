#include <Gamebuino-Meta.h>
#include "Global.h"

extern Gamebuino_Meta::Sound_FX loseLife[] = {
  {Gamebuino_Meta::Sound_FX_Wave::NOISE,0,184,0,-19,96,11},
};

extern Gamebuino_Meta::Sound_FX SLostlife[] = {
  {Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,192,-1,49,22,21},
};

extern Gamebuino_Meta::Sound_FX SBonus[] = {
  {Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,150,-6,-44,53,4},
};

void Game::init() {
    this -> _state   = this -> GameState::TITLESCREEN;
    this -> _oldTime = 0;
    this -> lightSides = false;
    this -> sound = false;
    if (this -> sound) {
        gb.sound.tone(987, 160);
        delay(160);
        gb.sound.tone(1318, 400);
    }
    this -> currentLevelNb  = 1;
    this -> lives = 3;
    this -> score = 0;  
}


// Calculate DeltaTime
float_t Game::_calculateDeltaTime(){
    float currentTime = millis();
    float deltaTime = currentTime - this -> _oldTime;
    this -> _oldTime = currentTime;
    return deltaTime;
}

void Game::checkLives() {
    if (this -> lives <= 0) {
    delay(500);
    this -> _state   = this -> GameState::GAMEOVER;
  }
}

void Game::showInfos(){
  gb.display.setCursor(18, 4);
  gb.display.setColor(WHITE);
  gb.display.print(this -> currentLevelNb);
  gb.display.setCursor(40, 4);
  gb.display.setColor(WHITE);
  gb.display.print(this -> lives);
  gb.display.setCursor(64, 4);
  gb.display.setColor(WHITE);
  gb.display.print(this -> score);
}



// Load High scores
void Game::_initHighScore(){
  for(byte thisScore = 0; thisScore < this -> _NUM_HIGHSCORE; thisScore++){
    this -> _highscore[thisScore] = gb.save.get(2*thisScore);
    gb.save.get(2*thisScore + 1, this -> _name[thisScore],this ->  _NAME_LENGTH+1);
  }
}


// Save HighScore
void Game::_saveHighScore(unsigned int test_score) {

    if (test_score > (this -> _highscore[_NUM_HIGHSCORE-1])){  //if it's a highscore
          gb.getDefaultName(this -> _name[this -> _NUM_HIGHSCORE-1]);
          gb.gui.keyboard("Name", this -> _name[_NUM_HIGHSCORE-1]);
          this -> _highscore[_NUM_HIGHSCORE-1] = test_score;
          for(byte i= this -> _NUM_HIGHSCORE-1; i>0; i--){ //bubble sorting FTW
              if(this -> _highscore[i-1] < this -> _highscore[i]){
                  char tempName[this -> _NAME_LENGTH];
                  strcpy(tempName, this -> _name[i-1]);
                  strcpy(this -> _name[i-1], this -> _name[i]);
                  strcpy(this -> _name[i], tempName);
                  unsigned int tempScore;
                  tempScore = this -> _highscore[i-1];
                  this -> _highscore[i-1] = _highscore[i];
                  this -> _highscore[i] = tempScore;
              } else {
                  break;
              }
          }
          
          for(byte thisScore = 0; thisScore < this -> _NUM_HIGHSCORE; thisScore++){
              gb.save.set(2*thisScore, this -> _highscore[thisScore]);
              gb.save.set(2*thisScore + 1, this -> _name[thisScore]);
          }
    } // end of highscore test part
}



void Game::loop() {

    _deltaTime = _calculateDeltaTime();
  
    switch (_state) {
      
      case GameState::TITLESCREEN:
          ball.newBall();
          this -> _state = GameState::RUNNING;
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
