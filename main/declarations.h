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
#include "heroes.h"
#include "enemies.h"
#include <map>

namespace heroMapCoordinates{
    uint8_t x = 10;
    uint8_t y = 10;
    uint8_t width = 8;
    uint8_t height = 8;
}

namespace screenDimension{
    const uint8_t highResWidth = 160;
    const uint8_t highResHeight = 128;
    const uint8_t lowResWidth = 80;
    const uint8_t lowResHeight = 64;
}

enum gameScreens{
    HERO_CHOOSING,
    MAP
}gameScreen;

std::vector<Hero*>heroes = {new Gunner(7, 3, "gunner"),
                            new Sniper(10, 0, "sniper"),
                            new Pope(6, 9, "pope"),
                            new Hacker(5, 5, "hacker"),
                            new Stalker(1, 9, "stalker")
};
// std::vector<Hero*> xd = {new Ghul(1,2,"f")};
auto currentHero = heroes.begin();
// auto currentEnemy = enemies.begin();

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
                if( heroMapCoordinates::x - 1 >= 0){
                    heroMapCoordinates::x--;
                }
            }else if(gb.buttons.repeat(BUTTON_RIGHT, 0)){
                if( heroMapCoordinates::x + 1 + heroMapCoordinates::width <= screenDimension::highResWidth){
                    heroMapCoordinates::x++;
                }
            }else if(gb.buttons.repeat(BUTTON_UP, 0)){
                if( heroMapCoordinates::y - 1 >= 0){
                    heroMapCoordinates::y--;
                }
            }else if(gb.buttons.repeat(BUTTON_DOWN, 0)){
                if( heroMapCoordinates::y + 1 + heroMapCoordinates::height <= screenDimension::highResHeight){
                    heroMapCoordinates::y++;
                }
            }
            break;
    } 
}

#endif

