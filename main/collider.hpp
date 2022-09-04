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
#include <set>
#include <memory>
// #include "heroes.hpp"
// #include "graphics.hpp"

struct Coordinates{
    int x, y, width, height;
    Coordinates(int x, int y, int width, int height){
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }
};

class Collider{
    public:
        void addInteractiveElement(int x, int y, int width, int height);
        void addBlockingElement(int x, int y, int width, int height);
        bool isBlockingCollided(int playerX, int playerY, int playerWidth, int playerHeight);
        bool isInteractiveCollided(int playerX, int playerY, int playerWidth, int playerHeight);
    private:
        std::set<std::shared_ptr<Coordinates>> blockingElements;
        std::set<std::shared_ptr<Coordinates>> interactiveElements;
};