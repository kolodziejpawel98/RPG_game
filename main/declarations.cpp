#include <Gamebuino-Meta.h>
#include "declarations.h"
#include "hero.h"
// #include "graphics.h"

namespace screenDimension{
    const uint8_t highResWidth = 160;
    const uint8_t highResHeight = 128;
    const uint8_t lowResWidth = 80;
    const uint8_t lowResHeight = 64;
    const uint8_t mapMovingPointLeft = 18;
    const uint8_t mapMovingPointRight = lowResWidth - 18;
    const uint8_t mapMovingPointUp = 18;
    const uint8_t mapMovingPointBottom = lowResHeight - 18;
    int mapPrzesuniecieX = -32;
    int mapPrzesuniecieY = -30;
}

enum gameScreens{
    HERO_CHOOSING,
    MAP,
    MAP_TO_LOCATION_POPUP,
    MAP_TO_TOWN_POPUP,
    LOCATION,
    TOWN
}gameScreen;

String debugLine = "xd";
int cursorPositionX = 16;
int cursorPositionY = 42;

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
        
        // gb.display.drawImage(screenDimension::mapPrzesuniecieX, screenDimension::mapPrzesuniecieY, mapWorldElements);
        gb.display.drawImage(screenDimension::mapPrzesuniecieX + 6, screenDimension::mapPrzesuniecieY, mapWorldPath);
        gb.display.drawImage(screenDimension::mapPrzesuniecieX + 100, screenDimension::mapPrzesuniecieY + 42, mapWorldForest); //stworzyc hardcode zmienne dla obiektow
        gb.display.drawImage(screenDimension::mapPrzesuniecieX + 26, screenDimension::mapPrzesuniecieY + 26, mapWorldTown); //32 + wymiar poczatkowy  => mapprzesuniecieX + wynik
        gb.display.drawImage(screenDimension::mapPrzesuniecieX + 34, screenDimension::mapPrzesuniecieY + 85, mapWorldCave);
        gb.display.drawImage(screenDimension::mapPrzesuniecieX + 6, screenDimension::mapPrzesuniecieY + 58, mapWorldCave);
        gb.display.drawImage(screenDimension::mapPrzesuniecieX + 26, screenDimension::mapPrzesuniecieY + 7, mapWorldCave);
        gb.display.drawImage(screenDimension::mapPrzesuniecieX + 34, screenDimension::mapPrzesuniecieY + 85, mapWorldCave);
        (*currentHero)->drawMapHeroIcon();
        // gb.display.fillRect(heroMapCoordinates::x, heroMapCoordinates::y, 3, 3);
        gb.display.setCursor(5, 47);
        gb.display.println(debugLine);
        collider();
    }else if(gameScreen == MAP_TO_LOCATION_POPUP){
        gb.display.setColor(greenBackground);
        gb.display.fillRect(0, 0, screenDimension::lowResWidth, screenDimension::lowResHeight);
        // gb.display.drawImage(screenDimension::mapPrzesuniecieX, screenDimension::mapPrzesuniecieY, mapWorldElements);
        gb.display.setColor(WHITE);
        gb.display.fillRect(8, 9, 64, 46);
        gb.display.setColor(BLUE);
        gb.display.fillRect(cursorPositionX, cursorPositionY, 13, 7);
        gb.display.setColor(BLACK);
        gb.display.setCursor(15, 15);
        gb.display.printf("Enter the\n        location?");
        gb.display.setCursor(18, 42);
        gb.display.printf("yes");
        gb.display.setCursor(52, 42);
        gb.display.printf("no");
        // gb.display.println(debugLine);
    }else if(gameScreen == MAP_TO_TOWN_POPUP){
        gb.display.setColor(greenBackground);
        gb.display.fillRect(0, 0, screenDimension::lowResWidth, screenDimension::lowResHeight);
        // gb.display.drawImage(screenDimension::mapPrzesuniecieX, screenDimension::mapPrzesuniecieY, mapWorldElements);
        gb.display.setColor(WHITE);
        gb.display.fillRect(8, 9, 64, 46);
        gb.display.setColor(BLUE);
        gb.display.fillRect(cursorPositionX, cursorPositionY, 13, 7);
        gb.display.setColor(BLACK);
        gb.display.setCursor(15, 15);
        gb.display.printf("Enter the\n        location?");
        gb.display.setCursor(18, 42);
        gb.display.printf("yes");
        gb.display.setCursor(52, 42);
        gb.display.printf("no");
        // gb.display.println(debugLine);
    }else if(gameScreen == LOCATION){
        gb.display.setCursor(20, 20);
        gb.display.printf("LOCATION!!!");
    }else if(gameScreen == TOWN){
        gb.display.setCursor(20, 20);
        gb.display.printf("TOWN!!!");
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
        case MAP_TO_LOCATION_POPUP:
            if (gb.buttons.pressed(BUTTON_LEFT)) {
                cursorPositionX = 16;
                cursorPositionY = 42;
            }else if(gb.buttons.pressed(BUTTON_RIGHT)){
                cursorPositionX = 46;
                cursorPositionY = 42;
            }else if(gb.buttons.pressed(BUTTON_A) && cursorPositionX == 16){
                gameScreen = LOCATION;
            }else if(gb.buttons.pressed(BUTTON_A) && cursorPositionX == 46){
                heroMapCoordinates::x -= 10; //to change
                heroMapCoordinates::y -= 10; //to change
                gameScreen = MAP;
            }
            break;
        case MAP_TO_TOWN_POPUP: //zmienic zeby popup byl jeden 
            if (gb.buttons.pressed(BUTTON_LEFT)) {
                cursorPositionX = 16;
                cursorPositionY = 42;
            }else if(gb.buttons.pressed(BUTTON_RIGHT)){
                cursorPositionX = 46;
                cursorPositionY = 42;
            }else if(gb.buttons.pressed(BUTTON_A) && cursorPositionX == 16){
                gameScreen = TOWN;
            }else if(gb.buttons.pressed(BUTTON_A) && cursorPositionX == 46){
                heroMapCoordinates::x += 13; //to change
                heroMapCoordinates::y += 13; //to change
                gameScreen = MAP;
            }
    } 
}

void collider(){
    gb.display.setColor(BLUE);
    gb.display.fillRect(screenDimension::mapPrzesuniecieX + 87, screenDimension::mapPrzesuniecieY + 85, 3, 3);
    // gb.display.setColor(YELLOW);
    // gb.display.fillRect(heroMapCoordinates::x - 10, heroMapCoordinates::y - 10, 8, 8);
    if(gb.collide.rectRect(heroMapCoordinates::x - 10, heroMapCoordinates::y - 10, 8, 8, screenDimension::mapPrzesuniecieX + 87, screenDimension::mapPrzesuniecieY + 85, 3, 3)){
        gameScreen = MAP_TO_LOCATION_POPUP;
    }else if(gb.collide.circleCircle(heroMapCoordinates::x, heroMapCoordinates::y, 7, screenDimension::mapPrzesuniecieX + 43 , screenDimension::mapPrzesuniecieY + 39 , 15)){
        gameScreen = MAP_TO_TOWN_POPUP;
    }
}

// int cursorPositionX_no = 46;
// int cursorPositionY_no = 42;
void mapToLocationWindow(){
    gameScreen = MAP_TO_LOCATION_POPUP;
    // gameScreen = LOCATION; gdy gracz kliknie yes
}