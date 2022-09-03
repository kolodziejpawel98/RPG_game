#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
    #include <Gamebuino-Meta.h>
#else
	#include "WProgram.h"
#endif
#undef max
#undef min
#include "hero.hpp"
#include "start_game.hpp"
#include <vector>
#include <memory>

extern std::vector<std::shared_ptr<Hero>>heroes;
extern std::vector<std::shared_ptr<Hero>>::iterator currentHero;

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