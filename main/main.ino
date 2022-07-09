#include <Gamebuino-Meta.h>
#include "declarations.h";

void setup() {
  gb.begin();
  gb.display.init(160, 128, ColorMode::index);
}    
 
void loop() {
  while(!gb.update());
  gb.display.clear();
  if(actualScreen == &MENU_HERO_CHOOSING){
    gb.display.setCursor(10, 5);
    gb.display.println("Choose Your\n    fighter!");
    gb.display.setColor(WHITE);
    buttonListener();
    gb.display.setCursor(26, 32);
    gb.display.println(charToArduinoString(currentHero->name));
    gb.display.setColor(WHITE);
    gb.display.drawRect(23, 29, 33, 12);
  }else if(actualScreen == &MAP){
    gb.display.println("!!MAP!");
  }
}

