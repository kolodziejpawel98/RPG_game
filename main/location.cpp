#include <Gamebuino-Meta.h>
#include "location.hpp"
// #include "start_game.hpp"


void location::screen::display(){
    gb.display.setColor(BLACK);
    gb.display.fillRect(0, 0, screenDimension::lowResWidth, screenDimension::lowResHeight);
    drawBlockingElement(0, 0, 10, 20);
}

void location::drawBlockingElement(int x, int y, int width, int height){
    gb.display.setColor(BLUE);
    gb.display.fillRect(x, y, width, height);
    locationCollider.addBlockingElement(x, y, width, height);
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