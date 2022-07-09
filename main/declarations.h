#ifndef _DECLARATIONS_h
#define _DECLARATIONS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#undef max
#undef min
#include <vector>
#include <memory>

class Hero{
    public:
        int attack;
        int defence;
        char name;
        Hero(int attack, int defence, char name): attack(attack), defence(defence), name(name) {}
        bool operator==(const Hero* hero) const{
            return attack == hero->attack and defence == hero->defence;
        }
        // virtual void specialAction() = 0;
};

class Warrior : public Hero{
    public:
        Warrior(int attack, int defence, char name) : Hero(attack, defence, name) {}
};

class Thief : public Hero{
    public:
        Thief(int attack, int defence, char name) : Hero(attack, defence, name) {}
};

std::vector<Hero*>heroes = {new Warrior(5,10,'w'), new Thief(13,2, 't')};
Hero* currentHero = heroes[0];

/*
std::vector<Hero*>heroes = {new Hero(1, 2, 'b'), new Hero(3, 5, 'a')};
Hero* currentHero = heroes[0];
*/


void nextHero(){
    if(currentHero == heroes[0]){ //if adres wskznika HERO == wk
      currentHero = heroes[1];
    }else if(currentHero == heroes[1]){
      currentHero = heroes[0];
    }
}

#endif

