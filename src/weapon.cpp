#include <iostream>
#include "../header/weapon.hpp"
#include "../header/Point.hpp"
#include"../header/Enemy.hpp"

using namespace std;

Weapon::Weapon(): weapon_damage(-5), weapon_type("stick"){}

void Weapon::weaponAttack(Enemy* target){
    
    target->damageTaken(this->weapon_damage);
}

void Weapon::change_weapon(Point* point){
    Point point;
    if (point->getPoint()==20){
        this->weapon_type="bat";
        this->weapon_damage=-12;
    }
    if (point->getPoint()==40){
        this->weapon_type="steel bat";
        this->weapon_damage=-26;
    }
    
    
}
string Weapon::getWeapon(){
    return this->weapon_type;
}

int Weapon::getWeaponDamage(){
    return this->weapon_damage;
}