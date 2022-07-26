#include <Gamebuino-Meta.h>
#include "declarations.h"
#include "hero.h"
// #include "graphics.h"

namespace heroMapCoordinates{
    uint8_t x = 10;
    uint8_t y = 10;
    uint8_t width = 8;
    uint8_t height = 8;
}

namespace screenDimension{
    const uint8_t highResWidth = 160;
    const uint8_t highResHeight = 128;
    const uint8_t lowResWidth = 80;
    const uint8_t lowResHeight = 64;
}

enum gameScreens{
    HERO_CHOOSING,
    MAP
}gameScreen;


void buttonListener(){
    switch(gameScreen){
        case HERO_CHOOSING:
            if (gb.buttons.pressed(BUTTON_LEFT)) {
                previousHero();
            }else if(gb.buttons.pressed(BUTTON_RIGHT)){
                nextHero();
            }else if(gb.buttons.pressed(BUTTON_A)){
                gameScreen = MAP;
            }
            break;
        case MAP:
            if (gb.buttons.repeat(BUTTON_LEFT, 0)) {
                if( heroMapCoordinates::x - 1 >= 0){
                    heroMapCoordinates::x--;
                }
            }else if(gb.buttons.repeat(BUTTON_RIGHT, 0)){
                if( heroMapCoordinates::x + 1 + heroMapCoordinates::width <= screenDimension::highResWidth){
                    heroMapCoordinates::x++;
                }
            }else if(gb.buttons.repeat(BUTTON_UP, 0)){
                if( heroMapCoordinates::y - 1 >= 0){
                    heroMapCoordinates::y--;
                }
            }else if(gb.buttons.repeat(BUTTON_DOWN, 0)){
                if( heroMapCoordinates::y + 1 + heroMapCoordinates::height <= screenDimension::highResHeight){
                    heroMapCoordinates::y++;
                }
            }
            break;
    } 
}

// void drawHeroInfo(){
    // Image avatar((*currentHero)->currentAvatar);
    // uint8_t move = 0;
    // gb.display.setColor(WHITE);
    // gb.display.setCursor(13, 13);
    // gb.display.println((*currentHero)->name);
    // gb.display.setCursor(69, 38);
    // gb.display.printf("%d", (*currentHero)->attack);
    // gb.display.setCursor(69, 47);
    // gb.display.printf("%d", (*currentHero)->defence);
    // gb.display.drawImage(35, 38, startSkillBar);
    // gb.display.drawImage(35, 47, startSkillBar);
    // for(uint8_t i = 0; i<(*currentHero)->attack; ++i){
    //     gb.display.drawImage(36 + move, 39, startSkillCell);
    //     move += 4;
    // }
    // move = 0;
    // for(uint8_t i = 0; i<(*currentHero)->defence; ++i){
    //     gb.display.drawImage(36 + move, 48, startSkillCell);
    //     move += 4;
    // }
    // gb.display.drawImage(4, 12, startLeftArrowDefault);
    // gb.display.drawImage(44, 12, startRightArrowDefault);

    // gb.display.drawImage(54, 2, avatar);
// }

void startGame(){
    buttonListener();
    if(gameScreen == HERO_CHOOSING){
        gb.display.drawImage(0, 0, startBackground);
        gb.display.setCursor(5, 38);
        gb.display.printf("Attack");
        gb.display.setCursor(5, 47);
        gb.display.printf("Defence");
        (*currentHero)->drawHeroElements();
    }else if(gameScreen == MAP){
        (*currentHero)->specialSkill();
        // gb.display.init(80, 64, ColorMode::index);
        // gb.display.setCursor(13, 13);
        // gb.display.printf("warrior:");
        // gb.display.setCursor(13, 19);
        // gb.display.printf("1 2 3 4 5 6 7 8 9 0 10:");
        // gb.display.setCursor(13, 34);
    }
}