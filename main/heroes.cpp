#include "heroes.h"
// #include <Gamebuino-Meta.h>

std::vector<Hero*>heroes = {
                            new Gunner(),
                            new Sniper(),
                            new Pope(),
                            new Hacker(),
                            new Stalker()
};

std::vector<Hero*>::iterator currentHero = heroes.begin();

void hero::previous(){
    if(currentHero == heroes.begin()){
        currentHero = heroes.end() - 1;
    }else{
        --currentHero;
    }
}

void hero::next(){
    ++currentHero;
    if(currentHero == heroes.end())
        currentHero = heroes.begin();
}

Sniper::Sniper() : Hero(8, 0, "sniper", startAvatarSniperCode, mapWorldSniperCode) {}

void Sniper::specialSkill(){
    //every hero should do different action
    // gb.display.printf("sniper special skill placeholder");
}

Pope::Pope() : Hero(8, 8, "pope", startAvatarPopeCode, mapWorldPopeCode) {}

void Pope::specialSkill(){
    // gb.display.printf("pope special skill placeholder");
}

Stalker::Stalker() : Hero(0, 8, "stalker", startAvatarStalkerCode, mapWorldStalkerCode) {}

void Stalker::specialSkill(){
    // gb.display.printf("stalker special skill placeholder");
}

Gunner::Gunner() : Hero(4, 4, "gunner", startAvatarGunnerCode, mapWorldGunnerCode) {}

void Gunner::specialSkill(){
    // gb.display.printf("gunner special skill placeholder");
}

Hacker::Hacker() : Hero(6, 2, "hacker", startAvatarHackerCode, mapWorldHackerCode) {}

void Hacker::specialSkill(){
    // gb.display.printf("hacker special skill placeholder");
}