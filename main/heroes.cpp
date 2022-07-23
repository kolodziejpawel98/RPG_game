#include "heroes.h"

Sniper::Sniper(uint8_t attack, uint8_t defence, String name) : Hero(attack, defence, name) {}

String Sniper::specialSkill(){
    return "big bang";
}

void Sniper::drawHeroInfo(){

}

Pope::Pope(uint8_t attack, uint8_t defence, String name) : Hero(attack, defence, name) {}

String Pope::specialSkill(){
    return "sticky fingers";
}

void Pope::drawHeroInfo(){
    
}

Stalker::Stalker(uint8_t attack, uint8_t defence, String name) : Hero(attack, defence, name) {}

String Stalker::specialSkill(){
    return "sticky fingers";
}

void Stalker::drawHeroInfo(){
    
}

Gunner::Gunner(uint8_t attack, uint8_t defence, String name) : Hero(attack, defence, name) {}

String Gunner::specialSkill(){
    return "sticky fingers";
}

void Gunner::drawHeroInfo(){
    
}

Hacker::Hacker(uint8_t attack, uint8_t defence, String name) : Hero(attack, defence, name) {}

String Hacker::specialSkill(){
    return "sticky fingers";
}

void Hacker::drawHeroInfo(){
    gb.display.printf("xddddd");
}