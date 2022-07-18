#include "heroes.h"

Warrior::Warrior(uint8_t attack, uint8_t defence, String name) : Hero(attack, defence, name) {}

String Warrior::specialSkill(){
    return "big bang";
}

Thief::Thief(uint8_t attack, uint8_t defence, String name) : Hero(attack, defence, name) {}

String Thief::specialSkill(){
    return "sticky fingers";
}