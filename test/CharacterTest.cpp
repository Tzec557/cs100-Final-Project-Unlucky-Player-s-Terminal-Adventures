#include "../header/Character.hpp"
#include <gtest/gtest.h>

TEST(CharacterTests, testinitializer){
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


// failing
TEST(CharacterTests, GetHealthTest) {
    Character *c = new Character("HealthTest");
    EXPECT_EQ(c->getHealth(), 20); // Assuming initial health is 20
}


//failing
TEST(CharacterTests, AddHealthTest) {
    Character *c = new Character("HealthAddTest");
    c->addHealth(70);
    EXPECT_EQ(c->getHealth(), 90);
}

//failing
TEST(CharacterTests, AddNegativeHealthTest) {
    Character *c = new Character("HealthAddNegativeTest");
    c->addHealth(-20); // Assuming adding negative health is allowed
    EXPECT_EQ(c->getHealth(), 0);
}


/*
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/
