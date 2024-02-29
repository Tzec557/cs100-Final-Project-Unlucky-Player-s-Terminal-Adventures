#include <iostream>
#include "../header/weapon.hpp"
#include"../header/Enemy.hpp"

using namespace std;

Weapon::Weapon(): weapon_damage(2), weapon_name("stick"){}

void Weapon::weaponAttack(){
    Enemy target;
    target.damageTaken(this->weapon_damage);
    //I will subtrat enemys health by weapn_damage and set that health.
}
