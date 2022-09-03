#include <Gamebuino-Meta.h>
#include "graphics.hpp"
#include "start_game.hpp"

void setup() {
  gb.begin();
  gb.setFrameRate(40); 
}    
 
void loop() {
  while(!gb.update());
  gb.display.clear();
  startGame();
}


