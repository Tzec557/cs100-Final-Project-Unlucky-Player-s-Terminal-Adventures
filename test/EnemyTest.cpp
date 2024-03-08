#include "../header/Enemy.hpp"
#include <gtest/gtest.h>

TEST(EnemyTests, testinitializer){
    Enemy *e = new Enemy();
    ASSERT_NE(e,nullptr);
}

TEST(EnemyTests, DamageTakenTest) {
    Enemy enemy; // Assuming the default health is initialized to 20 in the base class
    EXPECT_EQ(enemy.getHealth(), 20);

    enemy.damageTaken(30);
    EXPECT_EQ(enemy.getHealth(), 50);

    enemy.damageTaken(-10); // Assuming negative damage is allowed
    EXPECT_EQ(enemy.getHealth(), 40);
}

/*
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/
