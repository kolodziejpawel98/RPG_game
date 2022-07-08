#include <Gamebuino-Meta.h>
#include "declarations.h";

String menuHeroName = "";

void setup() {
  gb.begin();
}    
 
void loop() {
  while(!gb.update());
  gb.display.clear();
  gb.display.setCursor(10, 5);
  gb.display.println("Choose Your\n    fighter!");
  gb.display.setColor(WHITE);
  menu();
  gb.display.fillTriangle(37, 26, 40, 21, 43, 26);
  gb.display.fillTriangle(37, 43, 40, 48, 43, 43);
  gb.display.setCursor(26, 32);
  gb.display.println(charToArduinoString(currentHero.name));
  gb.display.setColor(WHITE);
  gb.display.drawRect(23, 29, 33, 12);
}

void menu(){
  if (gb.buttons.pressed(BUTTON_UP)) {
      gb.display.setColor(GREEN);
      nextHero();
    }else if(gb.buttons.pressed(BUTTON_DOWN)){
      gb.display.setColor(GREEN);
      nextHero();
    }
}

String charToArduinoString(char character){ //that's because arduino has problems with std::string
  if(character == 'b'){
    menuHeroName = "warrior";
  }else if(character == 'a'){
    menuHeroName = "thief";
  }
  return menuHeroName;
}


