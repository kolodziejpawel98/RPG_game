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
#include "../heroes.hpp"
#include "../graphics.hpp"

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