#include "heroes.h"

Sniper::Sniper(const uint16_t *currentAvatar) : Hero(8, 0, "sniper", currentAvatar) {}

String Sniper::specialSkill(){
    return "big bang";
}

void Sniper::drawHeroInfo(){

}

Pope::Pope(const uint16_t *currentAvatar) : Hero(5, 3, "pope", currentAvatar) {}

String Pope::specialSkill(){
    return "sticky fingers";
}

void Pope::drawHeroInfo(){
    
}

Stalker::Stalker(const uint16_t *currentAvatar) : Hero(0, 8, "stalker", currentAvatar) {}

String Stalker::specialSkill(){
    return "sticky fingers";
}

void Stalker::drawHeroInfo(){
    
}

Gunner::Gunner(const uint16_t *currentAvatar) : Hero(4, 4, "gunner", currentAvatar) {}

String Gunner::specialSkill(){
    return "sticky fingers";
}

void Gunner::drawHeroInfo(){
}

Hacker::Hacker(const uint16_t *currentAvatar) : Hero(6, 2, "hacker", currentAvatar) {}

String Hacker::specialSkill(){
    return "sticky fingers";
}

void Hacker::drawHeroInfo(){
    
}