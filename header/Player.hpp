#include <string>
#include"../header/Character.hpp"
using namespace std;

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player: public Character{
 public:
 	Player();
 	void damageDone(int num);
 };

#endif