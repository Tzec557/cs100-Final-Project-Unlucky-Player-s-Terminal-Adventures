#include <string>
#include"../header/Character.hpp"
#include "../header/Player.hpp"

using namespace std;

#ifndef ENEMY_HPP
#define ENEMY_HPP

class Enemy: public Character{
 private:
	int _damage;
 public:
 	Enemy();
	Enemy(string name);
 	void damageTaken(int num);
	void attack(Player *playerone);
 };

#endif
