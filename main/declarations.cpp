#include <Gamebuino-Meta.h>
#include "declarations.h"
#include "hero.h"
// #include "graphics.h"

enum gameScreens{
    START,
    HERO_CHOOSING,
    HERO_TO_MAP,
    MAP,
    MAP_TO_LOCATION_POPUP,
    MAP_TO_TOWN_POPUP,
    LOCATION,
    TOWN
}gameScreen;

String debugLine = "xd";

void startGame(){
    if(gameScreen == START){
        start::screen::display();
    }else if(gameScreen == HERO_CHOOSING){
        heroChoosing::screen::display();
    }else if(gameScreen == HERO_TO_MAP){
        
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
    buttonListener();
}

const std::pair <uint8_t, uint8_t> start::screen::startGameText(24, 28);
const std::pair <uint8_t, uint8_t> start::screen::exitGameText(24, 42);
// const std::pair <uint8_t, uint8_t> start::screen::cursor(14, 28);
std::shared_ptr<std::pair<uint8_t, uint8_t>> start::screen::currentOption = std::make_shared<std::pair<uint8_t, uint8_t>>(start::screen::startGameText);

void start::screen::display(){
    gb.display.drawImage(0, 0, startBackground);
    gb.display.drawImage(currentOption->first, currentOption->second, startRightArrowDefault); //cursor
    gb.display.setCursor(startGameText.first, startGameText.second);
    gb.display.printf("Start game");
    gb.display.setCursor(exitGameText.first, exitGameText.second);
    gb.display.printf("Exit");
    buttonListener::moveUp(); //zmienic nazwe na buttonListener
}

void start::buttonListener::moveUp(){ //BUG todo
    if(gb.buttons.pressed(BUTTON_DOWN) == true || gb.buttons.pressed(BUTTON_UP) == true){
        if(screen::currentOption.get() == &screen::startGameText){
                gb.display.setColor(RED);
        gb.display.fillRect(0, 0, screenDimension::lowResWidth, screenDimension::lowResHeight);
    
            screen::currentOption = std::make_shared<std::pair<uint8_t, uint8_t>>(screen::exitGameText);
        }else if(screen::currentOption.get() == &start::screen::exitGameText){
            screen::currentOption = std::make_shared<std::pair<uint8_t, uint8_t>>(screen::startGameText);
        }
    }
}

void heroChoosing::screen::display(){
    gb.display.drawImage(0, 0, startBackground);
    gb.display.setCursor(5, 38);
    gb.display.printf("Attack");
    gb.display.setCursor(5, 47);
    gb.display.printf("Defence");
    (*currentHero)->drawHeroElements();
}

void worldMap::screen::display(){
    gb.display.drawImage(screenDimension::mapPrzesuniecieX, screenDimension::mapPrzesuniecieY, mapWorldBackground);
    (*currentHero)->drawMapHeroIcon();
    // gb.display.setCursor(5, 47);
    // gb.display.println(debugLine); <-----------------
    collider();
}

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
}

void heroChoosing::buttonListener::nextHero(){
    hero::next();
}

void heroChoosing::buttonListener::previousHero(){
    hero::previous();
}

void heroChoosing::buttonListener::select(){
    gameScreen = MAP;
}

void worldMap::buttonListener::moveUp(){
    if( heroMapCoordinates::y == screenDimension::mapMovingPointUp )
        screenDimension::mapPrzesuniecieY++;
    else if( heroMapCoordinates::y - 1 >= 0 )
        heroMapCoordinates::y--;
}

void worldMap::buttonListener::moveDown(){
    if( heroMapCoordinates::y == screenDimension::mapMovingPointBottom )
        screenDimension::mapPrzesuniecieY--;
    else if( heroMapCoordinates::y + 1 + heroMapCoordinates::height <= screenDimension::highResHeight )
        heroMapCoordinates::y++;
}

void worldMap::buttonListener::moveLeft(){
    if( heroMapCoordinates::x == screenDimension::mapMovingPointLeft )
        screenDimension::mapPrzesuniecieX++;
    else if( heroMapCoordinates::x - 1 >= 0 )
        heroMapCoordinates::x--;
}

void worldMap::buttonListener::moveRight(){
    if( heroMapCoordinates::x == screenDimension::mapMovingPointRight )
        screenDimension::mapPrzesuniecieX--;
    else if( heroMapCoordinates::x + 1 + heroMapCoordinates::width <= screenDimension::highResWidth )
        heroMapCoordinates::x++;
}

void mapToLocation::buttonListener::yesHover(){
    cursorPosition::x = 16;
    cursorPosition::y = 42;
}

void mapToLocation::buttonListener::noHover(){
    cursorPosition::x = 46;
    cursorPosition::y = 42;
}

void mapToLocation::buttonListener::yesSelect(){ 
    if(gameScreen == MAP_TO_LOCATION_POPUP){ //FIXME
        gameScreen = LOCATION;
    }else if(gameScreen == MAP_TO_TOWN_POPUP){
        gameScreen = TOWN;
    }
}

void mapToLocation::buttonListener::noSelect(){
    heroMapCoordinates::x += 13;
    heroMapCoordinates::y += 13;
    gameScreen = MAP;
}

void buttonListener(){
    switch(gameScreen){
        case HERO_CHOOSING:
            if (gb.buttons.pressed(BUTTON_LEFT)) {
                heroChoosing::buttonListener::previousHero();
            }else if(gb.buttons.pressed(BUTTON_RIGHT)){
                heroChoosing::buttonListener::nextHero();
            }else if(gb.buttons.pressed(BUTTON_A)){
                heroChoosing::buttonListener::select();
            }
            break;
        case MAP:
            if (gb.buttons.repeat(BUTTON_LEFT, 0)) {
                worldMap::buttonListener::moveLeft();
            }else if(gb.buttons.repeat(BUTTON_RIGHT, 0)){
                worldMap::buttonListener::moveRight();
            }else if(gb.buttons.repeat(BUTTON_UP, 0)){
                worldMap::buttonListener::moveUp();
            }else if(gb.buttons.repeat(BUTTON_DOWN, 0)){
                worldMap::buttonListener::moveDown();
            }
            break;
        case MAP_TO_LOCATION_POPUP:
            if (gb.buttons.pressed(BUTTON_LEFT)) {
                mapToLocation::buttonListener::yesHover();
            }else if(gb.buttons.pressed(BUTTON_RIGHT)){
                mapToLocation::buttonListener::noHover();
            }else if(gb.buttons.pressed(BUTTON_A) && cursorPosition::x == 16){
                mapToLocation::buttonListener::yesSelect();
            }else if(gb.buttons.pressed(BUTTON_A) && cursorPosition::x == 46){
                mapToLocation::buttonListener::noSelect();
            }
            break;
        case MAP_TO_TOWN_POPUP:
            if (gb.buttons.pressed(BUTTON_LEFT)) {
                mapToLocation::buttonListener::yesHover();
            }else if(gb.buttons.pressed(BUTTON_RIGHT)){
                mapToLocation::buttonListener::noHover();
            }else if(gb.buttons.pressed(BUTTON_A) && cursorPosition::x == 16){
                mapToLocation::buttonListener::yesSelect();
            }else if(gb.buttons.pressed(BUTTON_A) && cursorPosition::x == 46){
               mapToLocation::buttonListener::noSelect();
            }
    } 
}

void collider(){
    gb.display.setColor(BLUE);
    // gb.display.fillRect(screenDimension::mapPrzesuniecieX + 87, screenDimension::mapPrzesuniecieY + 85, 3, 3);
    // gb.display.setColor(YELLOW);
    // gb.display.fillRect(heroMapCoordinates::x - 10, heroMapCoordinates::y - 10, 8, 8);
    // gb.display.fillCircle(screenDimension::mapPrzesuniecieX + 43 , screenDimension::mapPrzesuniecieY + 39 , 15);
    // if(gb.collide.rectRect(heroMapCoordinates::x - 10, heroMapCoordinates::y - 10, 8, 8, screenDimension::mapPrzesuniecieX + 87, screenDimension::mapPrzesuniecieY + 85, 3, 3)){
        // gameScreen = MAP_TO_LOCATION_POPUP;
    // }else if(gb.collide.circleCircle(heroMapCoordinates::x, heroMapCoordinates::y, 7, screenDimension::mapPrzesuniecieX + 43 , screenDimension::mapPrzesuniecieY + 39 , 15)){
        // gameScreen = MAP_TO_TOWN_POPUP;
    // }
}

// int cursorPositionX_no = 46;
// int cursorPositionY_no = 42;
// void mapToLocationWindow(){
//     gameScreen = MAP_TO_LOCATION_POPUP;
//     // gameScreen = LOCATION; gdy gracz kliknie yes
// }