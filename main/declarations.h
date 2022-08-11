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


namespace heroChoosing{
	namespace screen{
		void display();
	}
	namespace buttonListener{
		void nextHero();
		void xd();
		void previousHero();
		void select();
	}
}

namespace worldMap{
	namespace screen{
		void display();
	}
	namespace buttonListener{
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
	}
}

namespace mapToLocation{
	namespace screen{
		void display();
	}
	namespace buttonListener{
		void yesHover();
		void yesSelect();
		void noHover();
		void noSelect();
	}
}

void startGame();
// void nextHero();
// void previousHero();
void buttonListener();
void drawHeroInfo();
void collider();
void mapToLocationWindow();

