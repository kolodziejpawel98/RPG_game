#include <Gamebuino-Meta.h>
#include "start_game.hpp"
#include "hero.hpp"

gameScreens gameScreen;

void startGame(){
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
        gb.display.setCursor(20, 20);
        gb.display.printf("LOCATION!!!");
    }else if(gameScreen == TOWN){
        gb.display.setCursor(20, 20);
        gb.display.printf("TOWN!!!");
    }
}