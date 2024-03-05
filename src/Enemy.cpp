#include "../header/Enemy.hpp"
#include <iostream>

Enemy::Enemy() : Character("Boss") {
}

void Enemy::damageTaken(int num) {
   addHealth(num); 
}
