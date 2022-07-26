#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
    #include <Gamebuino-Meta.h>
#else
	#include "WProgram.h"
#endif
#undef max
#undef min
#include "graphics.h"

class Hero{
    public:
        uint8_t attack;
        uint8_t defence;
        String name;
        const uint16_t *currentAvatar;
        Hero(uint8_t attack, uint8_t defence, String name, const uint16_t *currentAvatar);
        bool operator==(const Hero* hero) const;
        virtual void specialSkill() = 0;
        void drawHeroElements();
};