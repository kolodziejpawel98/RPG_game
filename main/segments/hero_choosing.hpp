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