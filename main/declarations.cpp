#include <Gamebuino-Meta.h>
#include "declarations.h"
#include "hero.h"
// #include "graphics.h"

namespace heroMapCoordinates{ //do przeniesienia
    uint8_t x = 10;
    uint8_t y = 10;
    uint8_t width = 8;
    uint8_t height = 8;
}

enum gameScreens{
    HERO_CHOOSING,
    MAP
}gameScreen;

void startGame(){
    buttonListener();
    if(gameScreen == HERO_CHOOSING){
        gb.display.drawImage(0, 0, startBackground);
        gb.display.setCursor(5, 38);
        gb.display.printf("Attack");
        gb.display.setCursor(5, 47);
        gb.display.printf("Defence");
        (*currentHero)->drawHeroElements();
    }else if(gameScreen == MAP){
        (*currentHero)->specialSkill();
        gb.display.setColor(greenBackground);
        gb.display.fillRect(0, 0, screenDimension::lowResWidth, screenDimension::lowResHeight);
        gb.display.drawImage(-32, -30, mapWorldElementsCode);
        gb.display.setColor(RED);
        gb.display.fillRect(heroMapCoordinates::x, heroMapCoordinates::y, 3, 3);
    }
}

void buttonListener(){
    switch(gameScreen){
        case HERO_CHOOSING:
            if (gb.buttons.pressed(BUTTON_LEFT)) {
                previousHero();
            }else if(gb.buttons.pressed(BUTTON_RIGHT)){
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

// void mapMoving(){
//     if(heroMapCoordinates::x < screenDimension::mapMovingPointLeft){
//         gb.display.drawImage(-32 + (), -30, mapWorldElementsCode);
//     }else if(heroMapCoordinates::x > screenDimension::mapMovingPointRight){

//     }else if(heroMapCoordinates::y < screenDimension::mapMovingPointUp){

//     }else if(heroMapCoordinates::y < screenDimension::mapMovingPointBottom){

//     }

// }