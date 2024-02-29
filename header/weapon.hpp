#ifndef WEAPON_HPP
#define WEAPON_HPP

class Weapon {
    private:
        int weapon_damage;
        string weapon_name;
    public:
        Weapon();

        void weaponAttack();
};

#endif // _HPP