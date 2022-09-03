#include <Gamebuino-Meta.h>
#include "world_map.hpp"
#include "../start_game.hpp"

void worldMap::screen::display(){
    gb.display.drawImage(screenDimension::mapPrzesuniecieX, screenDimension::mapPrzesuniecieY, mapWorldBackground);
    (*currentHero)->drawMapHeroIcon();
    gb.display.setCursor(5, 47);
    String coordi = static_cast<String>(heroMapCoordinates::x) + " " + static_cast<String>(heroMapCoordinates::y);
    gb.display.println(coordi);
    collider();
    worldMap::buttonListener();
}

void worldMap::buttonListener(){
    if (gb.buttons.repeat(BUTTON_LEFT, 0)) {
        worldMap::action::moveLeft();
    }else if(gb.buttons.repeat(BUTTON_RIGHT, 0)){
        worldMap::action::moveRight();
    }else if(gb.buttons.repeat(BUTTON_UP, 0)){
        worldMap::action::moveUp();
    }else if(gb.buttons.repeat(BUTTON_DOWN, 0)){
        worldMap::action::moveDown();
    }
}

void worldMap::collider(){
    gb.display.setColor(BLUE);
    gb.display.fillCircle(screenDimension::mapPrzesuniecieX + 87 + 2, screenDimension::mapPrzesuniecieY + 85 + 2, 2);
    // gb.display.setColor(YELLOW);
    // gb.display.fillCircle(heroMapCoordinates::x - 10 + 4, heroMapCoordinates::y - 10 + 4, 4);
    // gb.display.setColor(RED);
    // gb.display.fillCircle(screenDimension::mapPrzesuniecieX + 43 , screenDimension::mapPrzesuniecieY + 39 , 15);
    if(gb.collide.circleCircle(
                            heroMapCoordinates::x - 10 + 4,
                            heroMapCoordinates::y - 10 + 4,
                            4,
                            screenDimension::mapPrzesuniecieX + 87 + 2,
                            screenDimension::mapPrzesuniecieY + 85 + 2,
                            2)){
        gameScreen = MAP_TO_LOCATION_POPUP;
    }else if(gb.collide.circleCircle(
                            heroMapCoordinates::x,
                            heroMapCoordinates::y,
                            4,
                            screenDimension::mapPrzesuniecieX + 43,
                            screenDimension::mapPrzesuniecieY + 39, 
                            10)){
        gameScreen = MAP_TO_TOWN_POPUP;
    }
}

void worldMap::action::moveUp(){
    if( heroMapCoordinates::y == screenDimension::mapMovingPointUp )
        screenDimension::mapPrzesuniecieY++;
    else if( heroMapCoordinates::y - 1 >= 0 )
        heroMapCoordinates::y--;
}

void worldMap::action::moveDown(){
    if( heroMapCoordinates::y == screenDimension::mapMovingPointBottom )
        screenDimension::mapPrzesuniecieY--;
    else if( heroMapCoordinates::y + 1 + heroMapCoordinates::height <= screenDimension::highResHeight )
        heroMapCoordinates::y++;
}

void worldMap::action::moveLeft(){
    if( heroMapCoordinates::x == screenDimension::mapMovingPointLeft )
        screenDimension::mapPrzesuniecieX++;
    else if( heroMapCoordinates::x - 1 >= 0 )
        heroMapCoordinates::x--;
}

void worldMap::action::moveRight(){
    if( heroMapCoordinates::x == screenDimension::mapMovingPointRight )
        screenDimension::mapPrzesuniecieX--;
    else if( heroMapCoordinates::x + 1 + heroMapCoordinates::width <= screenDimension::highResWidth )
        heroMapCoordinates::x++;
}