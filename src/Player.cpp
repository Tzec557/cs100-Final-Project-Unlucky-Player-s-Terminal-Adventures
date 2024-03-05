#include "../header/Player.hpp"
#include <string> 

Player::Player(const string& playername) : Character(playername) {
}

void Player::damageDone(int num) {
   addHealth(num);
}
