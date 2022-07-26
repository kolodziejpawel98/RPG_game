#include "heroes.h"
// #include <Gamebuino-Meta.h>


Sniper::Sniper(const uint16_t *currentAvatar) : Hero(8, 0, "sniper", currentAvatar) {}

void Sniper::specialSkill(){
    gb.display.printf("sniper special skill placeholder");
}

Pope::Pope(const uint16_t *currentAvatar) : Hero(5, 3, "pope", currentAvatar) {}

void Pope::specialSkill(){
    gb.display.printf("pope special skill placeholder");
}

Stalker::Stalker(const uint16_t *currentAvatar) : Hero(0, 8, "stalker", currentAvatar) {}

void Stalker::specialSkill(){
    gb.display.printf("stalker special skill placeholder");
}

Gunner::Gunner(const uint16_t *currentAvatar) : Hero(4, 4, "gunner", currentAvatar) {}

void Gunner::specialSkill(){
    gb.display.printf("gunner special skill placeholder");
}

Hacker::Hacker(const uint16_t *currentAvatar) : Hero(6, 2, "hacker", currentAvatar) {}

void Hacker::specialSkill(){
    gb.display.printf("hacker special skill placeholder");
}

std::vector<Hero*>heroes = {
                            new Gunner(startAvatarGunnerCode),
                            new Sniper(startAvatarSniperCode),
                            new Pope(startAvatarPopeCode),
                            new Hacker(startAvatarHackerCode),
                            new Stalker(startAvatarStalkerCode)
};

std::vector<Hero*>::iterator currentHero = heroes.begin();

void previousHero(){
    //first hero & leftarrow = bug!!!!!!!
    if(currentHero == heroes.begin()){
        currentHero = heroes.end();
    }else{
        --currentHero;
    }
}

void nextHero(){
    ++currentHero;
    if(currentHero == heroes.end())
        currentHero = heroes.begin();
}