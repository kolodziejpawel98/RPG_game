#ifndef _DECLARATIONS_h
#define _DECLARATIONS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#undef max
#undef min
#include <vector>
#include <memory>
#include "hero.h"
//############################################################

String menuHeroName = "";//????????????
// const int MENU_HERO_CHOOSING = 1;
// const int MAP = 2; //enum tu dac

enum gameScreens{
    HERO_CHOOSING,
    MAP
}gameScreen;

// const int* actualScreen = &GAME_SCREEN;
std::vector<Hero*>heroes = {new Warrior(5,10,"warrior"), new Thief(13,2, "thief")};
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
    gameScreen = MAP;
  }
}

#endif

