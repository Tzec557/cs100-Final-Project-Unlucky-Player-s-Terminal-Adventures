
#include "../header/Enemy.hpp"
#include "../header/Player.hpp"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

Enemy::Enemy() : Character("Boss") {
   _damage = 0;
}
Enemy::Enemy(string name) : Character(name) {
}

Enemy::~Enemy(){}

void Enemy::damageTaken(int num) {
   addHealth(num); 
}

void Enemy::setDamage(int damage) {
    _damage = damage;
}
void Enemy::attack(Player *playerone) {
   playerone->addHealth(_damage); 
}

int Enemy::randomInRange(int min, int max) {
   return min + rand() % ((max + 1) - min);
}

string Enemy::getRandomEnemyName(vector<string>& names) {
    int index = randomInRange(0, names.size() - 1);
    string name = names[index];
    names.erase(names.begin() + index);
    return name;
}


