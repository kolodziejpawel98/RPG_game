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
#include "heroes.h"
#include "graphics.h"

namespace start{
	namespace screen{
		extern std::pair <uint8_t, uint8_t> startGameText;
		extern std::pair <uint8_t, uint8_t> exitGameText;
		extern std::pair <uint8_t, uint8_t> *currentOption;
		void display();
	}
	void buttonListener();
	namespace action{
		void moveCursor();
		void select();
	}
}

namespace heroChoosing{
	namespace screen{
		void display();
	}
	void buttonListener();
	namespace action{
		void nextHero();
		void previousHero();
		void select();
	}
}

namespace heroToMap{
	namespace screen{
		void display();
	}
}

namespace worldMap{
	namespace screen{
		void display();
	}
	void buttonListener();
	void collider();
	namespace action{
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
	void buttonListener();
	namespace action{
		void yesHover();
		void yesSelect();
		void noHover();
		void noSelect();
	}
}

void startGame();
// void drawHeroInfo();
// void collider();
// void mapToLocationWindow();

