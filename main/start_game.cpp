#include <Gamebuino-Meta.h>
#include <Arduino.h>
#include "start_game.hpp"
#include "hero.hpp"
#include <set>

gameScreens gameScreen;

void startGame(){
    // gameScreen = LOCATION;//!!!!!!!!!!!!!!!!!!!!!!!!!!!
    if(gameScreen == START){
        start::screen::display();
    }else if(gameScreen == HERO_CHOOSING){
        heroChoosing::screen::display();
    }else if(gameScreen == HERO_TO_MAP){
        //animation
    }else if(gameScreen == MAP){
        worldMap::screen::display();
    }else if(gameScreen == MAP_TO_LOCATION_POPUP){
        mapToLocation::screen::display();
    }else if(gameScreen == MAP_TO_TOWN_POPUP){
        mapToLocation::screen::display();
    }else if(gameScreen == LOCATION){
        location::screen::display();
    }else if(gameScreen == TOWN){
        gb.display.setCursor(20, 20);
        gb.display.printf("TOWN!!!");
    }
}