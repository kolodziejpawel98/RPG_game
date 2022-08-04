#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
    #include <Gamebuino-Meta.h>
#else
	#include "WProgram.h"
#endif
#undef max
#undef min
#include "hero.h"
#include "declarations.h"
#include <vector>

extern std::vector<Hero*>heroes;
extern std::vector<Hero*>::iterator currentHero;
void nextHero();
void previousHero();

class Gunner : public Hero{
    public:
        Gunner(const uint16_t *currentAvatar, const uint16_t *currentMapIcon);
        void specialSkill() override;
};

class Sniper : public Hero{
    public:
        Sniper(const uint16_t *currentAvatar, const uint16_t *currentMapIcon);
        void specialSkill() override;
};

class Stalker : public Hero{
    public:
        Stalker(const uint16_t *currentAvatar, const uint16_t *currentMapIcon);
        void specialSkill() override;
};

class Pope : public Hero{
    public:
        Pope(const uint16_t *currentAvatar, const uint16_t *currentMapIcon);
        void specialSkill() override;
};

class Hacker : public Hero{
    public:
        Hacker(const uint16_t *currentAvatar, const uint16_t *currentMapIcon);
        void specialSkill() override;
};