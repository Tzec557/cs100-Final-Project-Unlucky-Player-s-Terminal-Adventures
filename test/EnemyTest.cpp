#include "../header/Enemy.hpp"
#include "../header/Player.hpp"
#include <gtest/gtest.h>
#include <vector>
#include <string>

TEST(EnemyTests, testinitializer) {
    Enemy *e = new Enemy();
    ASSERT_NE(e, nullptr);
}

TEST(EnemyTests, DefaultConstructorTest) {
    Enemy enemy;
    EXPECT_EQ(enemy.getName(), "Boss"); // Check if the default name is "Boss"
    EXPECT_EQ(enemy.getDamage(), 0); // Check if the default damage is 0
}

TEST(EnemyTests, ParameterizedConstructorTest) {
    std::string name = "Dragon";
    Enemy enemy(name);
    EXPECT_EQ(enemy.getName(), name); // Check if the name is set correctly
}

TEST(EnemyTests, DamageTakenTest) {
    Enemy enemy; // Assuming the default health is initialized to 20 in the base class
    EXPECT_EQ(enemy.getHealth(), 20);

    enemy.damageTaken(30);
    EXPECT_EQ(enemy.getHealth(), 50);

    enemy.damageTaken(-10); // Assuming negative damage is allowed
    EXPECT_EQ(enemy.getHealth(), 40);
}

TEST(EnemyTests, SetDamageTest) {
    Enemy enemy;
    enemy.setDamage(10); // Set the damage to 10
    EXPECT_EQ(enemy.getDamage(), 10); //Checko if the damage is 10
}


TEST(EnemyTests, AttackTest) {
    // Create an enemy and a player
    Enemy enemy;
    Player player;

    // Set enemy damage and player health
    enemy.setDamage(-10);
    player.setHealth(50);

    // Test enemy attack on player
    enemy.attack(&player);
    EXPECT_EQ(player.getHealth(), 40);
}

TEST(EnemyTests, RandomInRangeTest) {
    Enemy enemy;
    int min = 10;
    int max = 20;
    int result = enemy.randomInRange(min, max);
    EXPECT_GE(result, min); // Check if the result is greater than or equal to min
    EXPECT_LE(result, max); // Check if the result is less than or equal to max
}

TEST(EnemyTests, GetRandomEnemyNameTest) {
    vector<string> names = {"Enemy1"};
    Enemy enemy;
    string randomName = enemy.getRandomEnemyName(names);
    EXPECT_FALSE(randomName.empty()); // Check if the random name is not empty
    EXPECT_EQ(enemy.getName(),"Boss" );
    enemy.setName(randomName);
    EXPECT_EQ(enemy.getName(),"Enemy1" );
}