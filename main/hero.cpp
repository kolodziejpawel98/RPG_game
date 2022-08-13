#include "hero.h"
// #include <Gamebuino-Meta.h>

bool Hero::operator==(const Hero* hero) const{
    return attack == hero->attack && defence == hero->defence;
}

Hero::Hero(uint8_t attack, uint8_t defence, String name, const uint16_t *currentAvatar, const uint16_t *currentMapIcon) : 
            attack(attack), defence(defence), name(name), currentAvatar(currentAvatar), currentMapIcon(currentMapIcon) {}
            
void Hero::drawHeroElements(){
    Image avatar(currentAvatar);
    uint8_t move = 0;
    gb.display.setColor(WHITE);
    gb.display.setCursor(13, 13);
    gb.display.println(name);
    gb.display.setCursor(69, 38);
    gb.display.printf("%d", attack);
    gb.display.setCursor(69, 47);
    gb.display.printf("%d", defence);
    gb.display.drawImage(35, 38, startSkillBar);
    gb.display.drawImage(35, 47, startSkillBar);
    for(uint8_t i = 0; i<attack; ++i){
        gb.display.drawImage(36 + move, 39, startSkillCell);
        move += 4;
    }
    move = 0;
    for(uint8_t i = 0; i<defence; ++i){
        gb.display.drawImage(36 + move, 48, startSkillCell);
        move += 4;
    }
    gb.display.drawImage(4, 12, startLeftArrowDefault);
    gb.display.drawImage(44, 12, startRightArrowDefault);
    gb.display.drawImage(54, 2, avatar);
}

void Hero::drawMapHeroIcon(){
    Image mapIcon(currentMapIcon);
    gb.display.drawImage(heroMapCoordinates::x - 10, heroMapCoordinates::y - 10, mapIcon);
}