#include"../header/Enemy.hpp"
#include <gtest/gtest.h>


TEST(weaponSuite,testDamage){
    Enenmy enemy;
    
    int intial_health = enemy.getHealth()

    Weapon weapon;
    weapon.weaponAttack();

    EXPECT_LT(enemy.getHealth(), initial_health);


}