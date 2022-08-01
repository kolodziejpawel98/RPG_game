#include <Gamebuino-Meta.h>
#include "declarations.h"
#include "hero.h"
// #include "graphics.h"

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
    const uint8_t mapMovingPointLeft = 10;
    const uint8_t mapMovingPointRight = lowResWidth - 10;
    const uint8_t mapMovingPointUp = 10;
    const uint8_t mapMovingPointBottom = lowResHeight - 10;
    int mapPrzesuniecieX = -32;
    int mapPrzesuniecieY = -30;
}

enum gameScreens{
    HERO_CHOOSING,
    MAP
}gameScreen;

String debugLine = "xd";

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
        gb.display.setColor(RED);
        
        gb.display.drawImage(screenDimension::mapPrzesuniecieX, screenDimension::mapPrzesuniecieY, mapWorldElements);
        gb.display.fillRect(heroMapCoordinates::x, heroMapCoordinates::y, 3, 3);
        gb.display.setCursor(5, 47);
        gb.display.println(debugLine);
        collider();
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
                if( heroMapCoordinates::x == screenDimension::mapMovingPointLeft){
                        screenDimension::mapPrzesuniecieX++;
                }else if( heroMapCoordinates::x - 1 >= 0){
                    heroMapCoordinates::x--;
                }
            }else if(gb.buttons.repeat(BUTTON_RIGHT, 0)){
                if( heroMapCoordinates::x == screenDimension::mapMovingPointRight){
                        screenDimension::mapPrzesuniecieX--;
                }else if( heroMapCoordinates::x + 1 + heroMapCoordinates::width <= screenDimension::highResWidth){
                    heroMapCoordinates::x++;
                }
            }else if(gb.buttons.repeat(BUTTON_UP, 0)){
                if( heroMapCoordinates::y == screenDimension::mapMovingPointUp){
                        screenDimension::mapPrzesuniecieY++;
                }else if( heroMapCoordinates::y - 1 >= 0){
                    heroMapCoordinates::y--;
                }
            }else if(gb.buttons.repeat(BUTTON_DOWN, 0)){
                if( heroMapCoordinates::y == screenDimension::mapMovingPointBottom){
                        screenDimension::mapPrzesuniecieY--;
                }else if( heroMapCoordinates::y + 1 + heroMapCoordinates::height <= screenDimension::highResHeight){
                    heroMapCoordinates::y++;
                }
            }
            break;
    } 
}

void collider(){
    gb.display.setColor(BLUE);
    gb.display.fillRect(15, 15, 3, 3);
    if(gb.collide.rectRect(heroMapCoordinates::x, heroMapCoordinates::y, 3, 3, 15, 15, 3, 3)) debugLine += "c";
}
