#include "../header/Enemy.hpp"
#include <iostream>

Enemy::Enemy() : Character("Boss") {
}
Enemy::Enemy(string name) : Character(name) {
}
void Enemy::damageTaken(int num) {
   addHealth(num); 
}
