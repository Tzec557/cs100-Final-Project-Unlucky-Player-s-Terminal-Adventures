#include <gtest/gtest.h>
#include "../header/weapon.hpp"

TEST(WeaponTests, testinitializer){
    Weapon *t = new Weapon();
    ASSERT_NE(t,nullptr);
}
TEST(PlayerTests, batChangeWeapon){
    Point* tPoint = new Point();
    Weapon *t = new Weapon();

    tPoint->addPoint(20);
    t->change_weapon(tPoint);
    ASSERT_EQ(t->getWeapon(),"bat");
    ASSERT_EQ(t->getWeaponDamage(), -12);
}
TEST(PlayerTests, steelBatChangeWeapon){
    Point* tPoint = new Point();
    Weapon *t = new Weapon();

    tPoint->addPoint(40);
    t->change_weapon(tPoint);
    ASSERT_EQ(t->getWeapon(),"steel bat");
    ASSERT_EQ(t->getWeaponDamage(), -26);
}
TEST(PlayerTests, swordChangeWeapon){
    Point* tPoint = new Point();
    Weapon *t = new Weapon();

    tPoint->addPoint(60);
    t->change_weapon(tPoint);
    ASSERT_EQ(t->getWeapon(),"sword");
    ASSERT_EQ(t->getWeaponDamage(), -36);
}
TEST(PlayerTests, lightSaberChangeWeapon){
    Point* tPoint = new Point();
    Weapon *t = new Weapon();

    tPoint->addPoint(80);
    t->change_weapon(tPoint);
    ASSERT_EQ(t->getWeapon(),"light saber");
    ASSERT_EQ(t->getWeaponDamage(), -45);
}