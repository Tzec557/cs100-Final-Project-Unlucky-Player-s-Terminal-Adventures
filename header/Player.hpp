#ifndef PLAYER_HPP
#define PLAYER_HPP
#include"Character.hpp"
using namespace std;

class Player: public Character{
	public:
 		Player();
 		void damageDone(int num);
};

#endif