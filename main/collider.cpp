#include <Gamebuino-Meta.h>
#include "collider.hpp"
// #include "start_game.hpp"

void Collider::addBlockingElement(int x, int y, int width, int height){
    blockingElements.insert(std::make_shared<Coordinates>(x, y, width, height));
}

void Collider::addInteractiveElement(int x, int y, int width, int height){
    interactiveElements.insert(std::make_shared<Coordinates>(x, y, width, height));
}

bool Collider::isBlockingCollided(int playerX, int playerY, int playerWidth, int playerHeight){
    // std::find_if(myVector.begin(), myVector.end(), [&blockingElements](const MyStruct& x) { return x.m_id == toFind.m_id;});
    for(auto it : blockingElements) {
        if(gb.collide.rectRect(playerX, playerY, playerWidth, playerHeight, it->x, it->y, it->width, it->height)){
            return true;
        }else{
            return false;
        }
    }
}

bool Collider::isInteractiveCollided(int playerX, int playerY, int playerWidth, int playerHeight){
    for(auto it : interactiveElements) {
        if(gb.collide.rectRect(playerX, playerY, playerWidth, playerHeight, it->x, it->y, it->width, it->height)){
            return true;
        }else{
            return false;
        }
    }
}