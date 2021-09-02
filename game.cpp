#include <Gamebuino-Meta.h>
#include "Game.h"

void Game::Init() {
    _state   = GameState::TITLESCREEN;
}

void Game::Loop() {
  
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
