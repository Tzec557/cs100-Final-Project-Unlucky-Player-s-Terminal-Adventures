#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>
#include"../header/Character.hpp"
#include "../header/Player.hpp"
#include <vector>

using namespace std;

class Enemy: public Character{
 private:
    int _damage;
 public:
    Enemy();
    Enemy(string name);
    virtual ~Enemy();

    void damageTaken(int num);
    void attack(Player* playerone);
    int getDamage() const { return _damage; }
    string getRandomEnemyName(vector<string>& names);
    int randomInRange(int min, int max);
 };

#endif