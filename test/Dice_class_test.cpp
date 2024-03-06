#include <gtest/gtest.h>
#include "../header/dice.hpp"

TEST(DiceTests, testNullInitializer) {

	Dice *d = new Dice();

	ASSERT_NE(d, nullptr);

}

TEST(DiceTests, testRollDice) {
    Dice *d = new Dice();

    int rollResult = d->rollDice();

    // Check if rollResult is between 1 and 6, inclusive
    EXPECT_TRUE(rollResult >= 1 && rollResult <= 6);
}


