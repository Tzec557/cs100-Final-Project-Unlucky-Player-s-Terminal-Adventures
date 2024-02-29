#include"../header/Enemy.hpp"
#include<iostream>
using namespace std;

Enemy::Enemy() : Character(Boss){}

void Enemy::damageTaken(int num){
   _health = _health + num;
}