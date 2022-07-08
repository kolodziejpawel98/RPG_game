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

class Hero{
    public:
        int attack;
        int defence;
        char name;
        Hero(int attack, int defence, char name): attack(attack), defence(defence), name(name) {}
        bool operator==(const Hero& hero) const{
            return attack == hero.attack and defence == hero.defence;
        }
};

Hero warrior(1, 2, 'b');
Hero thief(3, 5, 'a');

std::vector<Hero>heroes = {warrior, thief};

Hero currentHero = heroes[0];

void nextHero(){
    if(currentHero == heroes[0]){
      currentHero = heroes[1];
    }else if(currentHero == heroes[1]){
      currentHero = heroes[0];
    }
}

#endif

