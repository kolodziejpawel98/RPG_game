#include <Gamebuino-Meta.h>
#include "hero_choosing.hpp"
#include "../start_game.hpp"

void heroChoosing::screen::display(){
    gb.display.drawImage(0, 0, startBackground);
    gb.display.setCursor(5, 38);
    gb.display.printf("Attack");
    gb.display.setCursor(5, 47);
    gb.display.printf("Defence");
    (*currentHero)->drawHeroElements();
    heroChoosing::buttonListener();
}

void heroChoosing::buttonListener(){
    if (gb.buttons.pressed(BUTTON_LEFT)) {
        heroChoosing::action::previousHero();
    }else if(gb.buttons.pressed(BUTTON_RIGHT)){
        heroChoosing::action::nextHero();
    }else if(gb.buttons.pressed(BUTTON_A)){
        heroChoosing::action::select();
    }
}

void heroChoosing::action::nextHero(){
    hero::next();
}

void heroChoosing::action::previousHero(){
    hero::previous();
}

void heroChoosing::action::select(){
    gameScreen = MAP;
}