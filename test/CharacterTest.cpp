#include "../header/Character.hpp"
#include <gtest/gtest.h>

TEST(CharacterTests, testinitializer){
    Character *c = new Character();
    ASSERT_NE(c,nullptr);
    delete c;
    
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
    Character *c = new Character("HealthTest");
    EXPECT_EQ(c->getHealth(), 20); // Assuming initial health is 20
    delete c;
}

TEST(CharacterTests, AddHealthTest) {
    Character *c = new Character("HealthAddTest");
    c->addHealth(70);
    EXPECT_EQ(c->getHealth(), 90);
    delete c;
}

TEST(CharacterTests, AddNegativeHealthTest) {
    Character *c = new Character("HealthAddNegativeTest");
    c->addHealth(-20); // Assuming adding negative health is allowed
    EXPECT_EQ(c->getHealth(), 0);
    delete c;
}

TEST(CharacterTests, SetHealthTest) {
    Character character;
    int health = 100;
    character.setHealth(health); // Set the health using the setHealth function
    EXPECT_EQ(character.getHealth(), health); // Check if the health is set correctly
}
