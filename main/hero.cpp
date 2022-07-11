#include "hero.h"

bool Hero::operator==(const Hero* hero) const{
    return attack == hero->attack && defence == hero->defence;
}

Hero::Hero(int attack, int defence, String name): attack(attack), defence(defence), name(name) {}

Warrior::Warrior(int attack, int defence, String name) : Hero(attack, defence, name) {}

String Warrior::specialSkill(){
    return "big bang";
}

Thief::Thief(int attack, int defence, String name) : Hero(attack, defence, name) {}

String Thief::specialSkill(){
    return "sticky fingers";
}