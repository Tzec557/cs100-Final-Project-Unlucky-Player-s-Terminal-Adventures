#include "../header/Player.hpp"
#include <string> 

Player::Player() : Character("playername") {
}

void Player::damageDone(int num) {
   addHealth(num);
}
