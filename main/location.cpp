#include <Gamebuino-Meta.h>
#include "location.hpp"
// #include "start_game.hpp"

String debugLine = "xd";

Collider locationCollider;

void location::screen::display(){
    gb.display.setColor(BLACK);
    gb.display.fillRect(0, 0, screenDimension::lowResWidth, screenDimension::lowResHeight);
    drawBlockingElement(12, 12, 2, 20);
    drawBlockingElement(12, 12, 20, 2);
    location::buttonListener();
    gb.display.setColor(RED);
    gb.display.fillRect(heroMapCoordinates::x, heroMapCoordinates::y, heroMapCoordinates::width, heroMapCoordinates::height);
}

void location::drawBlockingElement(int x, int y, int width, int height){
    gb.display.setColor(BLUE);
    gb.display.fillRect(x, y, width, height);
    if(!locationCollider.isBlockingElementExist(x, y, width, height)){
        locationCollider.addBlockingElement(x, y, width, height);
    }
}

void location::buttonListener(){
    if (gb.buttons.repeat(BUTTON_LEFT, 0)) {
        location::action::moveLeft();
    }else if(gb.buttons.repeat(BUTTON_RIGHT, 0)){
        location::action::moveRight();
    }else if(gb.buttons.repeat(BUTTON_UP, 0)){
        location::action::moveUp();
    }else if(gb.buttons.repeat(BUTTON_DOWN, 0)){
        location::action::moveDown();
    }
}

void location::action::moveUp(){
    if(!locationCollider.isBlockingElementCollided(
        heroMapCoordinates::x,
        heroMapCoordinates::y - 1,
        heroMapCoordinates::width,
        heroMapCoordinates::height)){
            heroMapCoordinates::y--;
    }
}

void location::action::moveDown(){
    if(!locationCollider.isBlockingElementCollided(
        heroMapCoordinates::x,
        heroMapCoordinates::y + 1,
        heroMapCoordinates::width,
        heroMapCoordinates::height)){
            heroMapCoordinates::y++;
    }
}

void location::action::moveLeft(){
    if(!locationCollider.isBlockingElementCollided(
        heroMapCoordinates::x - 1,
        heroMapCoordinates::y,
        heroMapCoordinates::width,
        heroMapCoordinates::height)){
            heroMapCoordinates::x--;
    }
}

void location::action::moveRight(){
    if(!locationCollider.isBlockingElementCollided(
        heroMapCoordinates::x + 1,
        heroMapCoordinates::y,
        heroMapCoordinates::width,
        heroMapCoordinates::height)){
            heroMapCoordinates::x++;
    }
}