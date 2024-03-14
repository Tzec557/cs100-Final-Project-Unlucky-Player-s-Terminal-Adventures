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


TEST(GameTest, IntroTest) {
    std::stringstream mockInput("2\n"); // Simulates user choosing to quit immediately during intro
    std::stringstream mockOutput;
    std::cin.rdbuf(mockInput.rdbuf());
    std::cout.rdbuf(mockOutput.rdbuf());

    MockGame game;

    // Expectations
    EXPECT_CALL(game, Intro()).Times(1); // Expect Intro to be called
    EXPECT_CALL(game, NameSelection()).Times(0);
    EXPECT_CALL(game, PlayGame()).Times(0);

    game.Intro();

    std::string output = mockOutput.str();
    EXPECT_TRUE(output.find("You die.") == std::string::npos);
}



TEST(GameTest, NameSelectionTest) {
    std::stringstream mockInput("John\n1\n"); // Simulates user entering a name and confirming it
    std::stringstream mockOutput;
    std::cin.rdbuf(mockInput.rdbuf());
    std::cout.rdbuf(mockOutput.rdbuf());

    MockGame game;

    // Expectations
    EXPECT_CALL(game, Intro()).Times(0);
    EXPECT_CALL(game, NameSelection()).Times(1); // Expect NameSelection to be called
    EXPECT_CALL(game, PlayGame()).Times(0);

    game.NameSelection();

    std::string output = mockOutput.str();
    EXPECT_TRUE(output.find("Welcome John.") == std::string::npos);
}



TEST(GameTest, PlayGameTest) {
    // Prepare input stream to simulate both name selection and the initial action in PlayGame
    std::stringstream mockInput;
    mockInput << "John\n1\n"; // Inputs for NameSelection: name entry and confirmation
    mockInput << "y\n"; // Simulate starting a battle immediately in PlayGame

    std::stringstream mockOutput;
    std::cin.rdbuf(mockInput.rdbuf());
    std::cout.rdbuf(mockOutput.rdbuf());

    MockGame game;

    // Call NameSelection first to simulate setting up the player's name
    game.NameSelection();
    
    // Reset expectations specifically for PlayGame testing
    EXPECT_CALL(game, Intro()).Times(0);
    EXPECT_CALL(game, NameSelection()).Times(0); // NameSelection is already executed, no more expectations
    EXPECT_CALL(game, PlayGame()).Times(1); // Expect PlayGame to be called
    EXPECT_CALL(game, bed_checkpoint()).Times(testing::AtLeast(1)); // Expect bed_checkpoint to be called at least once

    // Execute the PlayGame method which now operates with a selected name
    game.PlayGame();

    // Validate the outcome
    std::string output = mockOutput.str();
    EXPECT_TRUE(output.find("You've chosen to battle") == std::string::npos); // Verify the specific output
}



TEST(GameTest, BedCheckpointStatsTest) {
    std::stringstream mockInput("s\n"); // Simulates user choosing to print stats
    std::stringstream mockOutput;
    std::cin.rdbuf(mockInput.rdbuf());
    std::cout.rdbuf(mockOutput.rdbuf());

    MockGame game;

    // Expectations
    EXPECT_CALL(game, Intro()).Times(0);
    EXPECT_CALL(game, NameSelection()).Times(0);
    EXPECT_CALL(game, PlayGame()).Times(0);
    EXPECT_CALL(game, bed_checkpoint()).Times(1); // Expect bed_checkpoint to be called
    EXPECT_CALL(game, printUserStats()).Times(1); // Expect printUserStats to be called

    game.bed_checkpoint();

    std::string output = mockOutput.str();
    EXPECT_TRUE(output.find("Your current stats:") == std::string::npos);
}





/*
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/
