#include "Character.hpp"
#include <gtest/gtest.h>

Test(CharacterTests, testinitializer){
    Character *c = new Character();
    ASSERT_NE(c,nullptr);
}

TEST(CharacterTests, GetNameTest) {
    Character character("TestCharacter");
    EXPECT_EQ(character.getName(), "TestCharacter");
}

TEST(CharacterTests, SetNameTest) {
    Character character("OldName");
    character.setName("NewName");
    EXPECT_EQ(character.getName(), "NewName");
}

TEST(CharacterTests, GetHealthTest) {
    Character character("HealthTest");
    EXPECT_EQ(character.getHealth(), 0); // Assuming initial health is 0
}

TEST(CharacterTests, AddHealthTest) {
    Character character("HealthAddTest");
    character.addHealth(50);
    EXPECT_EQ(character.getHealth(), 50);
}

TEST(CharacterTests, AddNegativeHealthTest) {
    Character character("NegativeHealthTest");
    character.addHealth(-20); // Assuming adding negative health is allowed
    EXPECT_EQ(character.getHealth(), -20);
}

// Add more tests as needed

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


#include "../header/Enemy.hpp"

TEST(EnemyTests, DamageTakenTest) {
    Enemy enemy; // Assuming the default health is initialized to 0 in the base class
    EXPECT_EQ(enemy.getHealth(), 0);

    enemy.damageTaken(30);
    EXPECT_EQ(enemy.getHealth(), 30);

    enemy.damageTaken(-10); // Assuming negative damage is allowed
    EXPECT_EQ(enemy.getHealth(), 20);
}
