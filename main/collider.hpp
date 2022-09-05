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
// #include <set>
#include <memory>
#include <vector>
// #include "heroes.hpp"
// #include "graphics.hpp"

extern String colliderDebugLine;

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
        std::vector<std::shared_ptr<Coordinates>> blockingElements;
        std::vector<std::shared_ptr<Coordinates>> interactiveElements;
};