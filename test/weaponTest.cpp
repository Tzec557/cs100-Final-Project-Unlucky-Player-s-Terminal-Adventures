#include"../header/Enemy.hpp"
#include "../header/Point.hpp"
#include "../header/weapon.hpp"

#include <gtest/gtest.h>


TEST(weaponSuite,testDamage){
    Enenmy enemy;
    
    int intial_health = enemy.getHealth()

    Weapon weapon;
    weapon.weaponAttack();

    EXPECT_LT(enemy.getHealth(), initial_health);


}
TEST(weaponSuite,test_Weapon){
    Weapon weapon;
    
    EXPECT_EQ(weapon.getWeapon(), "stick");
    
    Points testPoints;
    testPoints.addPoint(101);
    
    weapon.change_weapon()

    EXPECT_EQ(weapon.getWeapon, "sword");


}