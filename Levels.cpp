#include <Gamebuino-Meta.h>
#include "Global.h"

//---------------------------------------------------------------------------
// Data for the levels
//---------------------------------------------------------------------------
// COLUMNS: 10   ROW: 5   BRICK: 8 x 4
// Briques
// 0: absence de brique            11: vie 
// 1: brique grise incassable      12: taille paddle ++
// 2: brique bleue foncée          13: taille paddle --
// 3: brique bleu moyen            14: glue
// 4: brique bleu claire           15: accélère balle
// 5: brique verte                 16: ralenti balle
// 6: brique jaune                 17: mini raquète
// 7: brique orange                18: perd une vie
// 8: brique rose                  19: taille de la balle --
// 9: brique marron                20: taille de la balle ++
// 10: brique violette             21: balle d'acier (traverse les briques)
//---------------------------------------------------------------------------

int8_t level_brick[this -> _NB_LEVEL][this -> ROWS * this -> COLUMNS + 1] = { 
  
 { 4, 4,  4,  6,  6,  6,  4,  6, 4,  6,
   6, 3,  6,  6,  6,  3,  6,  6, 3,  6,
  20, 3, 18,  3, 11,  3, 12,  7, 3, 12,
   2, 2, 11, 14,  7,  2,  7, 18, 2, 11,
   9, 2,  9,  9,  9,  9,  2,  9, 2,  2, 7 }, 
    
 { 9, 9, 19,  7,  7, 6, 6, 6, 6, 6,
  11, 7,  7, 11, 20, 6, 6, 6, 6, 6,
  18, 7, 14,  7, 18, 6, 6, 6, 6, 6,
   6, 6,  6,  6,  6, 6, 6, 6, 6, 6,
   6, 6,  6,  6,  6, 6, 6, 6, 6, 6, 7 },
    
 { 5, 10,  5,  1,  7,  7,  1,  5, 10,  5,
   5, 10, 14,  1,  7,  7,  1, 13, 10,  5,
   1, 10,  5,  1, 12, 12,  1,  5, 10,  1,
   2, 10,  2,  2,  2,  2,  2,  2, 10,  2,
   2, 10,  2,  2,  2,  2,  2,  2, 10,  2, 7 },
    
 { 2,  4,  4,  4,  4,  4,  4,  4,  4, 4,
   2,  3,  3, 18,  3, 20,  3, 14,  3, 4,
   2, 20, 12, 11, 14, 12, 18,  3, 12, 4,
   1,  1,  1,  1,  1,  1,  1,  2,  2, 4,
   1,  1,  1,  1,  1,  1,  1,  2,  2, 4, 3 }, 

 { 0,  0,  8, 18,  8,  8, 20, 8,  0, 0, 
   0,  8,  8,  0, 11,  8,  0, 8,  8, 0,
   0, 20,  8, 20,  8, 18,  8, 8, 20, 0, 
   0,  8,  8,  0,  0,  0,  0, 8,  8, 0,
   0,  0,  20, 8,  8,  8, 11, 8,  0, 0, 8 }, 

 { 2,  4, 1,  4,  4,  4,  4, 1,  4, 2, 
   2,  3, 1, 18,  3, 20,  3, 1,  3, 2, 
   2, 20, 1, 11, 14, 12, 18, 1, 12, 2, 
   2,  2, 1,  2,  2,  2,  2, 1,  2, 2, 
   2,  2, 1,  2,  2,  2,  2, 1,  2, 2, 3 }, 

{ 0, 18, 2, 2, 11, 1, 11, 2,  2, 18, 
  0,  2, 1, 1,  1, 1,  1, 1,  1,  2, 
  0,  2,20, 2,  2, 2,  2, 2, 20,  2, 
  0,  2, 2, 1,  1, 1,  1, 1,  2,  2, 
  0,  2, 1, 2,  2, 1,  2, 2,  1,  2, 2 }, 

 { 6,  6, 6, 9, 9, 9, 6, 1, 11, 19,
   6,  6, 6, 6, 9, 9, 6, 1, 7,  7, 
   9,  9, 9, 9, 6, 9, 6, 1, 7,  16,
   9,  6, 9, 6, 6, 9, 6, 1, 7,  7,
   9,  9, 9, 6, 6, 6, 6, 1, 7,  7, 7 }, 

 { 9, 7, 6, 5, 4, 3, 2, 1, 10, 8, 
   9, 7, 6, 5, 4, 3, 2, 1, 10, 8, 
   9, 7, 6, 5, 4, 3, 2, 1, 10, 8, 
   9, 7, 6, 5, 4, 3, 2, 1, 10, 8, 
   9, 7, 6, 5, 4, 3, 2, 1, 10, 8, 0 }, 

 { 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 
   9, 7, 7, 1, 1, 7, 7, 7, 7, 9,
   9, 7, 1, 7, 7, 7, 7, 1, 7, 9,
   9, 7, 1, 1, 1, 1, 1, 1, 7, 9,
   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0 }, 

    };
//---------------------------------------------------------------------------

void Level::resetCurrentLevel() {
  this -> brickCount = 0;
  this -> nbBricks = 0;
  this -> nbBonus = 0; 
  this -> defaultBonusBrick = this -> level_brick[game.level-1][50] ;
  for (int8_t row = 0; row < this -> _ROWS; row++)
    for (int8_t column = 0; column < this -> _COLUMNS; column++) { 
      currentLevel[row][column].type_brick = level_brick[game.level-1][row * this -> _COLUMNS + column];
      if (currentLevel[row][column].type_brick > 1) {
         this -> nbBricks++;
         currentLevel[row][column].isHit = false;
      } else if (currentLevel[row][column].type_brick == 1) {
         currentLevel[row][column].isHit = false;
      } else currentLevel[row][column].isHit = true;
    }
}

uint8_t Level::checkEndLevel() {
    if (this -> brickCount >= this -> nbBricks)  return (game.currentLevelNb + 1);
}

void Level::checkLevelEvent(){
    uint8_t newLevel = this -> checkEndLevel();
    if (newLevel > 0) {
      if (newLevel > this ->_NUM_LEVEL) newLevel = 1;
      this -> resetCurrenlevel();
    }
}