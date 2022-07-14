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
#include "hero.h"
#include <map>

enum gameScreens{
    HERO_CHOOSING,
    MAP
}gameScreen;

std::vector<Hero*>heroes = {new Warrior(5,10,"warrior"), new Thief(13,2, "thief")};
auto currentHero = heroes.begin();

void nextHero(){
    ++currentHero;
    if(currentHero == heroes.end())
        currentHero = heroes.begin();
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

