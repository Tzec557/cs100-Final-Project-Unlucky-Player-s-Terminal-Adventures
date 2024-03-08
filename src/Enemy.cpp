#include "../header/Enemy.hpp"
#include "../header/Player.hpp"
#include <iostream>

Enemy::Enemy() : Character("Boss") {
   _damage = 0;
}
Enemy::Enemy(string name) : Character(name) {
}

Enemy::~Enemy(){}

void Enemy::damageTaken(int num) {
   addHealth(num); 
}

void Enemy::attack(Player *playerone) {
   playerone->addHealth(_damage); 
}

