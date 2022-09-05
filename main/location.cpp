#include <Gamebuino-Meta.h>
#include "location.hpp"
// #include "start_game.hpp"

String debugLine = "xd";

Collider locationCollider;

void location::screen::display(){
    gb.display.setColor(BLACK);
    gb.display.fillRect(0, 0, screenDimension::lowResWidth, screenDimension::lowResHeight);
    gb.display.println(debugLine);
    drawBlockingElement(12, 12, 2, 20);
    drawBlockingElement(12, 12, 20, 2);
    location::buttonListener();
    gb.display.setColor(RED);
    gb.display.fillRect(heroMapCoordinates::x, heroMapCoordinates::y, heroMapCoordinates::width, heroMapCoordinates::height);
}

void location::drawBlockingElement(int x, int y, int width, int height){
    gb.display.setColor(BLUE);
    gb.display.fillRect(x, y, width, height);
    locationCollider.addBlockingElement(x, y, width, height);
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
    if(!locationCollider.isBlockingCollided(
        heroMapCoordinates::x,
        heroMapCoordinates::y - 1,
        heroMapCoordinates::width,
        heroMapCoordinates::height)){
            // debugLine = "xd?";
    gb.display.println(colliderDebugLine);
            heroMapCoordinates::y--;
    }
}

void location::action::moveDown(){
    heroMapCoordinates::y++;
}

void location::action::moveLeft(){
    heroMapCoordinates::x--;
}

void location::action::moveRight(){
    heroMapCoordinates::x++;
}
    
//     gb.display.fillCircle(screenDimension::mapPrzesuniecieX + 87 + 2, screenDimension::mapPrzesuniecieY + 85 + 2, 2);
//     // gb.display.setColor(YELLOW);
//     // gb.display.fillCircle(heroMapCoordinates::x - 10 + 4, heroMapCoordinates::y - 10 + 4, 4);
//     // gb.display.setColor(RED);
//     // gb.display.fillCircle(screenDimension::mapPrzesuniecieX + 43 , screenDimension::mapPrzesuniecieY + 39 , 15);
//     if(gb.collide.circleCircle(
//                             heroMapCoordinates::x - 10 + 4,
//                             heroMapCoordinates::y - 10 + 4,
//                             4,
//                             screenDimension::mapPrzesuniecieX + 87 + 2,
//                             screenDimension::mapPrzesuniecieY + 85 + 2,
//                             2)){
//         gameScreen = MAP_TO_LOCATION_POPUP;
//     }else if(gb.collide.circleCircle(
//                             heroMapCoordinates::x,
//                             heroMapCoordinates::y,
//                             4,
//                             screenDimension::mapPrzesuniecieX + 43,
//                             screenDimension::mapPrzesuniecieY + 39, 
//                             10)){
//         gameScreen = MAP_TO_TOWN_POPUP;
//     }
// }