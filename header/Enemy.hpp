#include <string>
#include"../header/Character.hpp"
using namespace std;

#ifndef ENEMY_HPP
#define ENEMY_HPP

class Enemy: public Character{
 public:
 	Enemy();
 	void damageTaken(int num);
 };

#endif
