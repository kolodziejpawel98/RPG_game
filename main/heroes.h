#ifndef _HEROES_h
#define _HEROES_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#undef max
#undef min
#include "hero.h"

class Warrior : public Hero{
    public:
        Warrior(uint8_t attack, uint8_t defence, String name);
        String specialSkill();
};

class Thief : public Hero{
    public:
        Thief(uint8_t attack, uint8_t defence, String name);
        String specialSkill();
};

#endif