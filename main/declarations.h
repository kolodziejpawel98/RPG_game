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
    const uint8_t width = 160;
    const uint8_t height = 128;
}

enum gameScreens{
    HERO_CHOOSING,
    MAP
}gameScreen;

std::vector<Hero*>heroes = {new Warrior(5, 10, "warrior"), new Thief(13, 2, "thief")};
// std::vector<Hero*>enemies = {new Troll(1, 2, "troll"), new Ghul(2, 3, "ghul")};
auto currentHero = heroes.begin();
// auto currentEnemy = enemies.begin();

void nextHero(){
    ++currentHero;
    if(currentHero == heroes.end())
        currentHero = heroes.begin();
}

// void nextEnemy(){
//     ++currentEnemy;
//     if(currentEnemy == enemies.end())
//         currentEnemy = enemies.begin();
// }

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
                if( heroMapCoordinates::x + 1 + heroMapCoordinates::width <= screenDimension::width){
                    heroMapCoordinates::x++;
                }
            }else if(gb.buttons.repeat(BUTTON_UP, 0)){
                if( heroMapCoordinates::y - 1 >= 0){
                    heroMapCoordinates::y--;
                }
            }else if(gb.buttons.repeat(BUTTON_DOWN, 0)){
                if( heroMapCoordinates::y + 1 + heroMapCoordinates::height <= screenDimension::height){
                    heroMapCoordinates::y++;
                }
            }
            break;
    } 
}

#endif

