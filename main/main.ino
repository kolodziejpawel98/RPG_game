#include <Gamebuino-Meta.h>
#include "declarations.h";

void setup() {
  gb.begin();
  gb.setFrameRate(60); 
  gb.display.init(160, 128, ColorMode::index);
}    
 
void loop() {
  while(!gb.update());
  gb.display.clear();
  if(gameScreen == HERO_CHOOSING){
    gb.display.setCursor(10, 5);
    gb.display.println("Choose Your\n    fighter!");
    gb.display.setColor(WHITE);
    buttonListener();
    gb.display.setCursor(26, 32);
    gb.display.println(currentHero->name);
    gb.display.setColor(WHITE);
    gb.display.drawRect(23, 29, 33, 12);
    gb.display.setCursor(13, 63);
    gb.display.printf("Attack: %d", currentHero->attack);
    gb.display.setCursor(13, 80);
    gb.display.printf("Defence: %d", currentHero->defence);
    gb.display.setCursor(13, 96);
    gb.display.println("Special skill: " + currentHero->specialSkill());
  }else if(gameScreen == MAP){
    gb.display.println("!!MAP!");
  }
}

