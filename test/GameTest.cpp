#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../header/Game.hpp"
#include <iostream>
#include <sstream>

using namespace std;
using ::testing::Return;


TEST(GameTests, testinitializer){
    Game *g = new Game();
    ASSERT_NE(g,nullptr);
}


class MockGame : public Game {
public:
    MOCK_METHOD(void, Intro, (), (override));
    MOCK_METHOD(void, NameSelection, (), (override));
    MOCK_METHOD(void, PlayGame, (), (override));
    MOCK_METHOD(void, StartGame, (), (override));
    MOCK_METHOD(void, printUserStats, (), (override));
    MOCK_METHOD(void, bed_checkpoint, (), (override));
};

TEST(GameTest, StartGameTest) {
    // Redirect cin and cout
    std::stringstream mockInput("2\n"); // Simulates user choosing to exit
    std::stringstream mockOutput;
    std::cin.rdbuf(mockInput.rdbuf());
    std::cout.rdbuf(mockOutput.rdbuf());

    // Instance of the game
    MockGame game;

    // Expectations
    EXPECT_CALL(game, Intro()).Times(0); // Expect Intro not to be called since we exit immediately
    EXPECT_CALL(game, NameSelection()).Times(0);
    EXPECT_CALL(game, PlayGame()).Times(0);

    // Execute
    game.StartGame();

    // Validate
    std::string output = mockOutput.str();
    EXPECT_TRUE(output.find("Please type a number to select an option:") != std::string::npos);
}


/*
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/
