#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#undef max
#undef min
#include "heroes.h"
#include "graphics.h"

void startGame();
void nextHero();
void previousHero();
void buttonListener();
void drawHeroInfo();
void collider();
void mapToLocationWindow();


