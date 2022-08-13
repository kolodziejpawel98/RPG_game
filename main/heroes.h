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
namespace hero{
    void next();
    void previous();
}

class Gunner : public Hero{
    public:
        Gunner();
        void specialSkill() override;
};

class Sniper : public Hero{
    public:
        Sniper();
        void specialSkill() override;
};

class Stalker : public Hero{
    public:
        Stalker();
        void specialSkill() override;
};

class Pope : public Hero{
    public:
        Pope();
        void specialSkill() override;
};

class Hacker : public Hero{
    public:
        Hacker();
        void specialSkill() override;
};