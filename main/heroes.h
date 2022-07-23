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
        Gunner(const uint16_t *currentAvatar);
        String specialSkill() override;
        void drawHeroInfo() override;
};

class Sniper : public Hero{
    public:
        Sniper(const uint16_t *currentAvatar);
        String specialSkill() override;
        void drawHeroInfo() override;
};

class Stalker : public Hero{
    public:
        Stalker(const uint16_t *currentAvatar);
        String specialSkill() override;
        void drawHeroInfo() override;
};

class Pope : public Hero{
    public:
        Pope(const uint16_t *currentAvatar);
        String specialSkill() override;
        void drawHeroInfo() override;
};

class Hacker : public Hero{
    public:
        Hacker(const uint16_t *currentAvatar);
        String specialSkill() override;
        void drawHeroInfo() override;
};

#endif