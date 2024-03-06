#include "../header/Player.hpp"
#include <string> 

Player::Player() : Character("playername") {
}

Player::Player(string name) : Character(name) {
}

void Player::damageDone(int num) {
   addHealth(num);
}
