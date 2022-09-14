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

bool Collider::isBlockingElementCollided(int playerX, int playerY, int playerWidth, int playerHeight){
    for(auto it : blockingElements) { //TODO find_if?
        colliderDebugLine = static_cast<String>(it->x);
        if(gb.collide.rectRect(playerX, playerY, playerWidth, playerHeight, it->x, it->y, it->width, it->height)){
            return true;
        }
    }
    return false;
}

bool Collider::isInteractiveElementCollided(int playerX, int playerY, int playerWidth, int playerHeight){
    for(auto it : interactiveElements) {
        if(gb.collide.rectRect(playerX, playerY, playerWidth, playerHeight, it->x, it->y, it->width, it->height)){
            return true;
        }
    }
    return false;
}

int Collider::getBlockingNum(){
    return blockingElements.size();
}

bool Collider::isBlockingElementExist(int x, int y, int width, int height){
    auto iterator = std::find_if(blockingElements.begin(), blockingElements.end(), [&x, &y, &width, &height](std::shared_ptr<Coordinates> element){
        return element->isCoordinateExist(x, y, width, height);
    });

    if(iterator != blockingElements.end()){
        return true;
    }else{
        return false;
    }
}