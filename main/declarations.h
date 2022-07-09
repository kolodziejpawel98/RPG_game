#ifndef _DECLARATIONS_h
#define _DECLARATIONS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#undef max
#undef min
#include "hero.h"
#include <vector>
#include <memory>

//############################################################

String menuHeroName = "";
const int MENU_HERO_CHOOSING = 1;
const int MAP = 2;
const int* actualScreen = &MENU_HERO_CHOOSING;
std::vector<Hero*>heroes = {new Warrior(5,10,'w'), new Thief(13,2, 't')};
Hero* currentHero = heroes[0];

void nextHero(){
    if(currentHero == heroes[0]){
      currentHero = heroes[1];
    }else if(currentHero == heroes[1]){
      currentHero = heroes[0];
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
  if(character == 'w'){
    menuHeroName = "warrior";
  }else if(character == 't'){
    menuHeroName = "thief";
  }
  return menuHeroName;
}


#endif

