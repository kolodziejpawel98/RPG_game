#include "hero.h"

bool Hero::operator==(const Hero* hero) const{
    return attack == hero->attack && defence == hero->defence;
}

Hero::Hero(uint8_t attack, uint8_t defence, String name): attack(attack), defence(defence), name(name) {}
