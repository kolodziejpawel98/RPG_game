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

namespace heroMapCoordinates{
    int x = 10;
    int y = 10;
}

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
    switch(gameScreen){
        case HERO_CHOOSING:
            if (gb.buttons.pressed(BUTTON_LEFT)) {
                gb.display.setColor(GREEN);
                nextHero();
            }else if(gb.buttons.pressed(BUTTON_RIGHT)){
                gb.display.setColor(GREEN);
                nextHero();
            }else if(gb.buttons.pressed(BUTTON_A)){
                gameScreen = MAP;
            }
            break;
        case MAP:
            if (gb.buttons.repeat(BUTTON_LEFT, 0)) {
                heroMapCoordinates::x--;
            }else if(gb.buttons.repeat(BUTTON_RIGHT, 0)){
                heroMapCoordinates::x++;
            }else if(gb.buttons.repeat(BUTTON_UP, 0)){
                heroMapCoordinates::y--;
            }else if(gb.buttons.repeat(BUTTON_DOWN, 0)){
                heroMapCoordinates::y++;
            }
            break;
    } 
}

#endif

