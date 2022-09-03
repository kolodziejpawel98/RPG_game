#include <Gamebuino-Meta.h>
#include "map_to_location.hpp"
#include "../start_game.hpp"

void mapToLocation::screen::display(){
    gb.display.drawImage(screenDimension::mapPrzesuniecieX, screenDimension::mapPrzesuniecieY, mapWorldBackground);
    gb.display.fillRect(0, 0, screenDimension::lowResWidth, screenDimension::lowResHeight);
    gb.display.setColor(WHITE);
    gb.display.fillRect(8, 9, 64, 46);
    gb.display.setColor(BLUE);
    gb.display.fillRect(cursorPosition::x, cursorPosition::y, 13, 7);
    gb.display.setColor(BLACK);
    gb.display.setCursor(15, 15);
    gb.display.printf("Enter the\n        location?");
    gb.display.setCursor(18, 42);
    gb.display.printf("yes");
    gb.display.setCursor(52, 42);
    gb.display.printf("no");
    mapToLocation::buttonListener();
}

void mapToLocation::buttonListener(){
    if (gb.buttons.pressed(BUTTON_LEFT)) {
        mapToLocation::action::yesHover();
    }else if(gb.buttons.pressed(BUTTON_RIGHT)){
        mapToLocation::action::noHover();
    }else if(gb.buttons.pressed(BUTTON_A) && cursorPosition::x == 16){
        mapToLocation::action::yesSelect();
    }else if(gb.buttons.pressed(BUTTON_A) && cursorPosition::x == 46){
        mapToLocation::action::noSelect();
    }
}

void mapToLocation::action::yesHover(){
    cursorPosition::x = 16;
    cursorPosition::y = 42;
}

void mapToLocation::action::noHover(){
    cursorPosition::x = 46;
    cursorPosition::y = 42;
}

void mapToLocation::action::yesSelect(){ 
    if(gameScreen == MAP_TO_LOCATION_POPUP){ //FIXME
        gameScreen = LOCATION;
    }else if(gameScreen == MAP_TO_TOWN_POPUP){
        gameScreen = TOWN;
    }
}

void mapToLocation::action::noSelect(){
    heroMapCoordinates::x += 13;
    heroMapCoordinates::y += 13;
    gameScreen = MAP;
}