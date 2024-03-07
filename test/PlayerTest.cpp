#include "../header/Player.hpp"
#include <gtest/gtest.h>

TEST(PlayerTests, testinitializer){
    Player *p = new Player();
    ASSERT_NE(p,nullptr);
}

TEST(PlayerTests, DamageDoneTest) {
    Player player; // Assuming the default health is initialized to 20 in the base class
    EXPECT_EQ(player.getHealth(), 20);

    player.damageDone(30);
    EXPECT_EQ(player.getHealth(), 50);

    player.damageDone(-10); // Assuming negative damage is allowed
    EXPECT_EQ(player.getHealth(), 40);
}


/*
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/

