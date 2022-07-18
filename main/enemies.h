#ifndef _ENEMIES_h
#define _ENEMIES_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#undef max
#undef min
#include "hero.h"

class Troll : public Hero{
    public:
        Troll(uint8_t attack, uint8_t defence, String name);
        String specialSkill();
};

class Ghul : public Hero{
    public:
        Ghul(uint8_t attack, uint8_t defence, String name);
        String specialSkill();
};

#endif