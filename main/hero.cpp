#include "hero.h"

bool Hero::operator==(const Hero* hero) const{
    return attack == hero->attack && defence == hero->defence;
}

Hero::Hero(int attack, int defence, char name): attack(attack), defence(defence), name(name) {}

Warrior::Warrior(int attack, int defence, char name) : Hero(attack, defence, name) {}

Thief::Thief(int attack, int defence, char name) : Hero(attack, defence, name) {}
