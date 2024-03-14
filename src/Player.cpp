#include "../header/Player.hpp"
#include <string> 

Player::Player() : Character("playername") {
}

Player::Player(string name) : Character(name) {
}

Player::~Player(){}

void Player::damageDone(int num) {
   addHealth(num);
}
