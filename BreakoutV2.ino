//----------------------------------------------------------------------    
//                     Breakout v2 by Jicehel
//             
//----------------------------------------------------------------------    

#include <Gamebuino-Meta.h>
#include "Global.h"

void setup() {
    gb.begin();
    gb.setFrameRate(60);
    game.init();
}

void loop() {
    gb.waitForUpdate();
    game.loop();
}
