#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#undef max
#undef min
#include <utility>
#include "heroes.h"
#include "graphics.h"

namespace start{
	namespace screen{
		extern const std::pair <uint8_t, uint8_t> startGameText;
		extern const std::pair <uint8_t, uint8_t> exitGameText;
		// extern const std::pair <uint8_t, uint8_t> cursor;
		extern std::shared_ptr<std::pair<uint8_t, uint8_t>> currentOption;
		void display();
	}
	namespace buttonListener{
		void moveDown();
		void moveUp();
		void select();
	}
}

namespace heroChoosing{
	namespace screen{
		void display();
	}
	namespace buttonListener{
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
void buttonListener();
void drawHeroInfo();
void collider();
void mapToLocationWindow();

