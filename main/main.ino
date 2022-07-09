#include <Gamebuino-Meta.h>
#include "declarations.h";

String menuHeroName = "";
const int MENU_HERO_CHOOSING = 1;
const int MAP = 2;
const int* actualScreen = &MENU_HERO_CHOOSING;

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

void buttonListener(){
  if (gb.buttons.pressed(BUTTON_LEFT)) {
    gb.display.setColor(GREEN);
    nextHero();
  }else if(gb.buttons.pressed(BUTTON_RIGHT)){
    gb.display.setColor(GREEN);
    nextHero();
  }else if(gb.buttons.pressed(BUTTON_A)){
    actualScreen = &MAP;
  }
}

String charToArduinoString(char character){ //that's because arduino has problems with std::string
  // gb.display.println(character);
  if(character == 'w'){
    menuHeroName = "warrior";
  }else if(character == 't'){
    menuHeroName = "thief";
  }
  return menuHeroName;
}


