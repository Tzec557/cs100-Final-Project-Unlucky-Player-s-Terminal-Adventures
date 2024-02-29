#include <iostream>
#include <stdexcept>
using namespace std;

#include "../hearder/Character.h"

Character::Character(string name){
    _health = 20;
    _name = name;
}

Character::~Character(){
}

void Character::getName(){
    return _name;
}
void Character::setName(string name){
    _name = name
}
void Character::getHealth(){
    return _health;
}
void Character::addHealth(int num){
    _health = _health + num;
}