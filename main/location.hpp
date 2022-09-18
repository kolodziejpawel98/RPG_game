#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#undef max
#undef min
#include <utility>
#include <string>
#include <memory>
#include "heroes.hpp"
#include "graphics.hpp"
#include "collider.hpp"
#include "menu.hpp"

extern Collider locationCollider;
extern Menu menu;
extern String debugLine;
extern bool wasCalledOnce;

namespace location{
	namespace screen{
		void display();
	}
	void setup();
	void buttonListener();
    void drawBlockingElement(int x, int y, int width, int height);
	void drawInteractiveElement(int x, int y, int width, int height);
	void animation();
	namespace action{
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
	}
}