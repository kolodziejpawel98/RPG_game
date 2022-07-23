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

class Gunner : public Hero{
    public:
        Gunner(uint8_t attack, uint8_t defence, String name);
        String specialSkill() override;
        void drawHeroInfo() override;
};

class Sniper : public Hero{
    public:
        Sniper(uint8_t attack, uint8_t defence, String name);
        String specialSkill() override;
        void drawHeroInfo() override;
};

class Stalker : public Hero{
    public:
        Stalker(uint8_t attack, uint8_t defence, String name);
        String specialSkill() override;
        void drawHeroInfo() override;
};

class Pope : public Hero{
    public:
        Pope(uint8_t attack, uint8_t defence, String name);
        String specialSkill() override;
        void drawHeroInfo() override;
};

class Hacker : public Hero{
    public:
        Hacker(uint8_t attack, uint8_t defence, String name);
        String specialSkill() override;
        void drawHeroInfo() override;
};

#endif