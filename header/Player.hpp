#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "../header/Character.hpp"

#include <string>

using namespace std;

class Player: public Character{
	public:
 		Player();
		Player(string name);
		virtual ~Player();
 		void damageDone(int num);
};

#endif
