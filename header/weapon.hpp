#ifndef WEAPON_HPP
#define WEAPON_HPP
using namespace std;
class Weapon {
    private:
        int weapon_damage;
        string weapon_type;
    public:
        Weapon();
        string getWeapon();

        void change_weapon();

        void weaponAttack();
};

#endif // _HPP
