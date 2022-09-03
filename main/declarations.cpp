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
        //anim
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
    // buttonListener();
}

//////////////////////////////////////// start //////////////////////////////////////// temporary file division

std::pair <uint8_t, uint8_t> start::screen::startGameText(24, 28);
std::pair <uint8_t, uint8_t> start::screen::exitGameText(24, 42);
std::pair <uint8_t, uint8_t> *start::screen::currentOption = &start::screen::startGameText;

void start::screen::display(){
    // gb.display.drawImage(0, 0, startBackground);
    gb.display.drawImage(start::screen::currentOption->first - 10, start::screen::currentOption->second, startRightArrowDefault); //cursor
    gb.display.setCursor(startGameText.first, startGameText.second);
    gb.display.printf("Start game");
    gb.display.setCursor(exitGameText.first, exitGameText.second);
    gb.display.printf("Exit");
    gb.display.setCursor(exitGameText.first, exitGameText.second + 8);
    // gb.display.println(debugLine);
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
       debugLine = "EXIT"; 
    }
}

//////////////////////////////////////// heroChoosing.cpp //////////////////////////////////////// temporary file division

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

//////////////////////////////////////// heroToMap.cpp //////////////////////////////////////// temporary file division

//////////////////////////////////////// worldMap.cpp //////////////////////////////////////// temporary file division

void worldMap::screen::display(){
    gb.display.drawImage(screenDimension::mapPrzesuniecieX, screenDimension::mapPrzesuniecieY, mapWorldBackground);
    (*currentHero)->drawMapHeroIcon();
    // 
    // gb.display.println(debugLine); <-----------------
    gb.display.setCursor(5, 47);
    String coordi = static_cast<String>(heroMapCoordinates::x) + " " + static_cast<String>(heroMapCoordinates::y);
    gb.display.println(coordi);
    collider();
    worldMap::buttonListener();
}

void worldMap::buttonListener(){
    if (gb.buttons.repeat(BUTTON_LEFT, 0)) {
        worldMap::action::moveLeft();
    }else if(gb.buttons.repeat(BUTTON_RIGHT, 0)){
        worldMap::action::moveRight();
    }else if(gb.buttons.repeat(BUTTON_UP, 0)){
        worldMap::action::moveUp();
    }else if(gb.buttons.repeat(BUTTON_DOWN, 0)){
        worldMap::action::moveDown();
    }
}

void worldMap::collider(){
    gb.display.setColor(BLUE);
    gb.display.fillCircle(screenDimension::mapPrzesuniecieX + 87 + 2, screenDimension::mapPrzesuniecieY + 85 + 2, 2);
    // gb.display.setColor(YELLOW);
    // gb.display.fillCircle(heroMapCoordinates::x - 10 + 4, heroMapCoordinates::y - 10 + 4, 4);
    // gb.display.setColor(RED);
    // gb.display.fillCircle(screenDimension::mapPrzesuniecieX + 43 , screenDimension::mapPrzesuniecieY + 39 , 15);
    if(gb.collide.circleCircle(
                            heroMapCoordinates::x - 10 + 4,
                            heroMapCoordinates::y - 10 + 4,
                            4,
                            screenDimension::mapPrzesuniecieX + 87 + 2,
                            screenDimension::mapPrzesuniecieY + 85 + 2,
                            2)){
        gameScreen = MAP_TO_LOCATION_POPUP;
    }else if(gb.collide.circleCircle(
                            heroMapCoordinates::x,
                            heroMapCoordinates::y,
                            4,
                            screenDimension::mapPrzesuniecieX + 43,
                            screenDimension::mapPrzesuniecieY + 39, 
                            10)){
        gameScreen = MAP_TO_TOWN_POPUP;
    }
}

void worldMap::action::moveUp(){
    if( heroMapCoordinates::y == screenDimension::mapMovingPointUp )
        screenDimension::mapPrzesuniecieY++;
    else if( heroMapCoordinates::y - 1 >= 0 )
        heroMapCoordinates::y--;
}

void worldMap::action::moveDown(){
    if( heroMapCoordinates::y == screenDimension::mapMovingPointBottom )
        screenDimension::mapPrzesuniecieY--;
    else if( heroMapCoordinates::y + 1 + heroMapCoordinates::height <= screenDimension::highResHeight )
        heroMapCoordinates::y++;
}

void worldMap::action::moveLeft(){
    if( heroMapCoordinates::x == screenDimension::mapMovingPointLeft )
        screenDimension::mapPrzesuniecieX++;
    else if( heroMapCoordinates::x - 1 >= 0 )
        heroMapCoordinates::x--;
}

void worldMap::action::moveRight(){
    if( heroMapCoordinates::x == screenDimension::mapMovingPointRight )
        screenDimension::mapPrzesuniecieX--;
    else if( heroMapCoordinates::x + 1 + heroMapCoordinates::width <= screenDimension::highResWidth )
        heroMapCoordinates::x++;
}


//////////////////////////////////////// mapToLocation.cpp //////////////////////////////////////// temporary file division

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