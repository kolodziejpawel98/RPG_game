#ifndef _HERO_h
#define _HERO_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#undef max
#undef min


class Hero{
    public:
        uint8_t attack;
        uint8_t defence;
        String name;
        Hero(uint8_t attack, uint8_t defence, String name);
        bool operator==(const Hero* hero) const;
        virtual String specialSkill() = 0;
};

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