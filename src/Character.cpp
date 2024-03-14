#include <iostream>
#include <string>
#include "../header/Character.hpp"

Character::Character() : _health(20), _name("") {}

Character::Character(std::string name) : _health(20), _name(name) {}

Character::~Character() {}

std::string Character::getName() const {
    return _name;
}

void Character::setName(std::string name) {
    _name = name;
}

int Character::getHealth() const {
    return _health;
}

void Character::addHealth(int health) {
    _health += health;
}

void Character::setHealth(int num){
    _health = num;
}
