#include"../header/Player.hpp"
#include<iostream>
using namespace std;

Player::Player() : Character("Player"){}

void Player::damageDone(int num){
   _health += num;
}
