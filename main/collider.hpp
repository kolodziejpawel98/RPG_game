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
#include <algorithm>
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
    bool isCoordinateExist(int x, int y, int width, int height){
        if(this->x == x && this->y == y && this->width == width && this->height == height){
            return true;
        }else return false;
    }
};

class Collider{
    public:
        void addInteractiveElement(int x, int y, int width, int height);
        void addBlockingElement(int x, int y, int width, int height);
        bool isBlockingElementCollided(int playerX, int playerY, int playerWidth, int playerHeight);
        bool isInteractiveElementCollided(int playerX, int playerY, int playerWidth, int playerHeight);
        bool isBlockingElementExist(int x, int y, int width, int height);
        bool isInteractiveElementExist(int x, int y, int width, int height);
    private:
        std::vector<std::shared_ptr<Coordinates>> blockingElements;
        std::vector<std::shared_ptr<Coordinates>> interactiveElements;
};