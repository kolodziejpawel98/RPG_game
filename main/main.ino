#include <Gamebuino-Meta.h>
#include "graphics.h"
#include "declarations.h"

void setup() {
  gb.begin();
  gb.setFrameRate(40); 
}    
 
void loop() {
  while(!gb.update());
  gb.display.clear();
  startGame();
}


