#include <iostream>
#include "../header/Character.hpp"
#include <stdexcept>
using namespace std;

Character::Character(){
    _health = 20;
    _name = "";
}
Character::Character(string name){
    _health = 20;
    _name = name;
}

Character::~Character(){
}

string Character::getName(){
    return _name;
}
void Character::setName(string name){
    _name = name;
}
int Character::getHealth(){
    return _health;
}
void Character::addHealth(int num){
    _health = _health + num;
}