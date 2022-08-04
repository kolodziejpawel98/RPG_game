#include "heroes.h"
// #include <Gamebuino-Meta.h>

std::vector<Hero*>heroes = {
                            new Gunner(startAvatarGunnerCode, mapWorldGunnerCode),
                            new Sniper(startAvatarSniperCode, mapWorldSniperCode),
                            new Pope(startAvatarPopeCode, mapWorldPopeCode),
                            new Hacker(startAvatarHackerCode, mapWorldHackerCode),
                            new Stalker(startAvatarStalkerCode, mapWorldStalkerCode)
};

std::vector<Hero*>::iterator currentHero = heroes.begin();

void previousHero(){
    if(currentHero == heroes.begin()){
        currentHero = heroes.end() - 1;
    }else{
        --currentHero;
    }
}

void nextHero(){
    ++currentHero;
    if(currentHero == heroes.end())
        currentHero = heroes.begin();
}

Sniper::Sniper(const uint16_t *currentAvatar, const uint16_t *currentMapIcon) : Hero(8, 0, "sniper", currentAvatar, currentMapIcon) {}

void Sniper::specialSkill(){
    //every hero should do different action
    gb.display.printf("sniper special skill placeholder");
}

Pope::Pope(const uint16_t *currentAvatar, const uint16_t *currentMapIcon) : Hero(8, 8, "pope", currentAvatar, currentMapIcon) {}

void Pope::specialSkill(){
    gb.display.printf("pope special skill placeholder");
}

Stalker::Stalker(const uint16_t *currentAvatar, const uint16_t *currentMapIcon) : Hero(0, 8, "stalker", currentAvatar, currentMapIcon) {}

void Stalker::specialSkill(){
    gb.display.printf("stalker special skill placeholder");
}

Gunner::Gunner(const uint16_t *currentAvatar, const uint16_t *currentMapIcon) : Hero(4, 4, "gunner", currentAvatar, currentMapIcon) {}

void Gunner::specialSkill(){
    gb.display.printf("gunner special skill placeholder");
}

Hacker::Hacker(const uint16_t *currentAvatar, const uint16_t *currentMapIcon) : Hero(6, 2, "hacker", currentAvatar, currentMapIcon) {}

void Hacker::specialSkill(){
    gb.display.printf("hacker special skill placeholder");
}