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
#include "start.hpp"
#include "hero_choosing.hpp"
#include "hero_to_map.hpp"
#include "map_to_location.hpp"
#include "world_map.hpp"
#include "location.hpp"
#include "graphics.hpp"

enum gameScreens{
    START,
    HERO_CHOOSING,
    HERO_TO_MAP,
    MAP,
    MAP_TO_LOCATION_POPUP,
    MAP_TO_TOWN_POPUP,
    LOCATION,
    TOWN
};
extern gameScreens gameScreen;

void startGame();



