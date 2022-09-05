#include <Gamebuino-Meta.h>
#include "collider.hpp"
// #include "start_game.hpp"

String colliderDebugLine = "";

void Collider::addBlockingElement(int x, int y, int width, int height){
    blockingElements.push_back(std::make_shared<Coordinates>(x, y, width, height));
}

void Collider::addInteractiveElement(int x, int y, int width, int height){
    interactiveElements.push_back(std::make_shared<Coordinates>(x, y, width, height));
}

bool Collider::isBlockingCollided(int playerX, int playerY, int playerWidth, int playerHeight){
    for(auto it : blockingElements) { //TODO find_if?
        if(gb.collide.rectRect(playerX, playerY, playerWidth, playerHeight, it->x, it->y, it->width, it->height)){
            return true;
        }
    }
    return false;
}

bool Collider::isInteractiveCollided(int playerX, int playerY, int playerWidth, int playerHeight){
    for(auto it : interactiveElements) { //TODO find_if?
        if(gb.collide.rectRect(playerX, playerY, playerWidth, playerHeight, it->x, it->y, it->width, it->height)){
            return true;
        }
    }
    return false;
}