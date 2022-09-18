#include <Gamebuino-Meta.h>
#include "location.hpp"

String debugLine = "xd";

Collider locationCollider;
Menu menu;
bool wasCalledOnce = false;

void location::screen::display(){
    if(!wasCalledOnce){
        setup();
    }
    gb.display.setColor(BLACK);
    gb.display.fillRect(0, 0, screenDimension::lowResWidth, screenDimension::lowResHeight);
    drawBlockingElement(12, 12, 2, 20);
    drawBlockingElement(12, 12, 20, 2);
    drawInteractiveElement(20, 20, 5, 5);
    gb.display.println(debugLine);
    location::buttonListener();
    gb.display.setColor(WHITE);
    gb.display.fillRect(heroMapCoordinates::x, heroMapCoordinates::y, heroMapCoordinates::width, heroMapCoordinates::height);
    if(locationCollider.isInteractiveElementCollided(
        heroMapCoordinates::x,
        heroMapCoordinates::y,
        heroMapCoordinates::width,
        heroMapCoordinates::height)){
        debugLine = "collision";
        gb.display.setColor(BLACK);
        gb.display.fillRect(0, 0, screenDimension::lowResWidth, screenDimension::lowResHeight);
        menu.display();
    }else{
        debugLine = "no";
    }
}

void location::setup(){
    menu.addMenuOption(10, 10, "buy item");
    menu.addMenuOption(10, 20, "sold item");
    menu.addMenuOption(10, 30, "take quest");
    wasCalledOnce = true;
}

void location::drawBlockingElement(int x, int y, int width, int height){
    gb.display.setColor(BLUE);
    gb.display.fillRect(x, y, width, height);
    if(!locationCollider.isBlockingElementExist(x, y, width, height)){
        locationCollider.addBlockingElement(x, y, width, height);
    }
}

void location::drawInteractiveElement(int x, int y, int width, int height){
    gb.display.setColor(RED);
    gb.display.fillRect(x, y, width, height);
    if(!locationCollider.isInteractiveElementExist(x, y, width, height)){
        locationCollider.addInteractiveElement(x, y, width, height);
    }
}

// void location::animation(){
//     static uint8_t frameCounter = 0;
//     frameCounter++;
//     gb.display.setColor(WHITE);
//     if(frameCounter == 3){
//         // gb.display.fillRect(0, 0, screenDimension::lowResWidth, screenDimension::lowResHeight);
//         gb.display.fillRect(0, screenDimension::lowResHeight - 20, 10, screenDimension::lowResHeight);
//     }else if(frameCounter == 6){
//         gb.display.fillRect(0, screenDimension::lowResHeight - 20, 13, screenDimension::lowResHeight);
//     }else if(frameCounter == 9){
//         gb.display.fillRect(0, screenDimension::lowResHeight - 20, 16, screenDimension::lowResHeight);
//     }else if(frameCounter == 12){
//         gb.display.fillRect(0, screenDimension::lowResHeight - 20, 19, screenDimension::lowResHeight);
//     }else if(frameCounter == 15){
//         gb.display.fillRect(0, screenDimension::lowResHeight - 20, 21, screenDimension::lowResHeight);
//     }else if(frameCounter == 18){
//         gb.display.fillRect(0, screenDimension::lowResHeight - 20, 24, screenDimension::lowResHeight);
//     }else if(frameCounter == 21){
//         frameCounter = 0;
//     }
// }

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