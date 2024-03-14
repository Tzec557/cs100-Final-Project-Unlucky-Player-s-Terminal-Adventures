#ifndef WEAPON_HPP
#define WEAPON_HPP
#include "../header/Enemy.hpp"
using namespace std;
class Weapon {
    private:
        int weapon_damage;
        string weapon_type;
    public:
        Weapon();
        string getWeapon();

        void change_weapon(Point*);

        void weaponAttack(Enemy*);
        int getWeaponDamage();
};

#endif // _HPP