#include <Gamebuino-Meta.h>
#include "start.hpp"
#include "../start_game.hpp"

std::pair <uint8_t, uint8_t> start::screen::startGameText(24, 28);
std::pair <uint8_t, uint8_t> start::screen::exitGameText(24, 42);
std::pair <uint8_t, uint8_t> *start::screen::currentOption = &start::screen::startGameText;

void start::screen::display(){
    gb.display.drawImage(start::screen::currentOption->first - 10, start::screen::currentOption->second, startRightArrowDefault); //cursor
    gb.display.setCursor(startGameText.first, startGameText.second);
    gb.display.printf("Start game");
    gb.display.setCursor(exitGameText.first, exitGameText.second);
    gb.display.printf("Exit");
    gb.display.setCursor(exitGameText.first, exitGameText.second + 8);
    start::buttonListener();
}

void start::buttonListener(){
    if(gb.buttons.pressed(BUTTON_DOWN) == true || gb.buttons.pressed(BUTTON_UP) == true){
       start::action::moveCursor();
    }else if(gb.buttons.pressed(BUTTON_A)){
        start::action::select();   
    }
}

void start::action::moveCursor(){
    if(start::screen::currentOption == &screen::startGameText){
        start::screen::currentOption = &screen::exitGameText;
    }else if(start::screen::currentOption == &screen::exitGameText){
        start::screen::currentOption = &screen::startGameText;
    }  
}

void start::action::select(){
    if(start::screen::currentOption == &screen::startGameText){
        gameScreen = HERO_CHOOSING;
    }else if(start::screen::currentOption == &screen::exitGameText){
        //...
    }
}
