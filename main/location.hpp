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

extern Collider locationCollider;

extern String debugLine;

namespace location{
	namespace screen{
		void display();
	}
	void buttonListener();
	// void collider();
    void drawBlockingElement(int x, int y, int width, int height);
	namespace action{
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
	}
}