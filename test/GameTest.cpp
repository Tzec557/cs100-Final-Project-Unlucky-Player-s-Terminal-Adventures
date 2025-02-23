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
    delete g;
}


class MockGame : public Game {
public:
    MOCK_METHOD(void, Intro, (), (override));
    MOCK_METHOD(void, NameSelection, (), (override));
    MOCK_METHOD(void, PlayGame, (), (override));
    MOCK_METHOD(void, StartGame, (), (override));
    MOCK_METHOD(void, printUserStats, (), (override));
    MOCK_METHOD(void, bed_checkpoint, (), (override));
    MOCK_METHOD(void, battle, (), (override));
};


TEST(GameTest, IntroDeathTest) {
    std::stringstream mockInput("2\n"); // Simulates user choosing to quit immediately during intro
    std::stringstream mockOutput;
    //recently added
    std::streambuf* originalCin = std::cin.rdbuf();
    std::streambuf* originalCout = std::cout.rdbuf();
    //
    std::cin.rdbuf(mockInput.rdbuf());
    std::cout.rdbuf(mockOutput.rdbuf());

    //Game game;
    Game game;//test add
    //test add
    //EXPECT_CALL(game, Intro()).Times(1);
    //EXPECT_CALL(game, PlayGame()).Times(0);  // Ensure PlayGame is not called
    //EXPECT_CALL(game, NameSelection()).Times(0);
    //
    game.Intro();

    std::string output = mockOutput.str();

    EXPECT_TRUE(output.find("Invalid Input. Enter option again:") == std::string::npos);
    EXPECT_TRUE(output.find("You die.") != std::string::npos);  //first was !=
     
     //test add
    // Restore original stream buffers
    std::cin.rdbuf(originalCin);
    std::cout.rdbuf(originalCout);


}

TEST(GameTest, IntroContinueTest) {
    std::stringstream mockInput("1\n"); // Simulates user choosing to play
    std::stringstream mockOutput;

    std::streambuf* originalCin = std::cin.rdbuf(); //capture orginal stream buffer
    std::streambuf* originalCout = std::cout.rdbuf();
    
    std::cin.rdbuf(mockInput.rdbuf());
    std::cout.rdbuf(mockOutput.rdbuf());

    Game game;

    game.Intro();

    std::string output = mockOutput.str();
    EXPECT_TRUE(output.find("Invalid Input. Enter option again:") == std::string::npos);
    EXPECT_TRUE(output.find("You die.") == std::string::npos);

    std::cin.rdbuf(originalCin);//restore orginal stream buffer
    std::cout.rdbuf(originalCout);
}




TEST(GameTest, IntroInvalidTest) {
    std::stringstream mockInput("a\n2\n"); // Simulates user choosing to play
    std::stringstream mockOutput;
    
    std::streambuf* originalCin = std::cin.rdbuf();
    std::streambuf* originalCout = std::cout.rdbuf();
    
    std::cin.rdbuf(mockInput.rdbuf());
    std::cout.rdbuf(mockOutput.rdbuf());

    Game game;

    game.Intro();

    std::string output = mockOutput.str();
    EXPECT_TRUE(output.find("Invalid Input. Enter option again:") != std::string::npos);
    EXPECT_TRUE(output.find("You die.") != std::string::npos);

    std::cin.rdbuf(originalCin);
    std::cout.rdbuf(originalCout);
}





TEST(GameTest, PrintUserStatsTest) {
    std::stringstream mockInput("John\n1\n"); // Simulate name selection
    std::stringstream mockOutput;

    std::streambuf* originalCin = std::cin.rdbuf();
    std::streambuf* originalCout = std::cout.rdbuf();

    std::cin.rdbuf(mockInput.rdbuf());
    std::cout.rdbuf(mockOutput.rdbuf());

    Game game;

    game.NameSelection(); 
    game.printUserStats();

    std::string output = mockOutput.str();
    EXPECT_TRUE(output.find("current weapon: stick") != std::string::npos);
    EXPECT_TRUE(output.find("weapons damage: -5") != std::string::npos);
    EXPECT_TRUE(output.find("current health: 20") != std::string::npos);
    EXPECT_TRUE(output.find("current points: 0") != std::string::npos);

    std::cin.rdbuf(originalCin);
    std::cout.rdbuf(originalCout);

}




TEST(GameTest, NameSelectionTest) {
    std::stringstream mockInput("John\n1\n"); // Simulates user entering a name and confirming it
    std::stringstream mockOutput;
    
    std::streambuf* originalCin = std::cin.rdbuf();
    std::streambuf* originalCout = std::cout.rdbuf();
    
    std::cin.rdbuf(mockInput.rdbuf());
    std::cout.rdbuf(mockOutput.rdbuf());

    Game game;

    game.NameSelection();

    std::string output = mockOutput.str();
    EXPECT_TRUE(output.find("Welcome John.") != std::string::npos);


    std::cin.rdbuf(originalCin);
    std::cout.rdbuf(originalCout);
}

TEST(GameTest, NameSelectionQuitTest) {
    std::stringstream mockInput("John\n2\n"); // Simulates user entering a name and confirming it
    std::stringstream mockOutput;

    std::streambuf* originalCin = std::cin.rdbuf();
    std::streambuf* originalCout = std::cout.rdbuf();

    std::cin.rdbuf(mockInput.rdbuf());
    std::cout.rdbuf(mockOutput.rdbuf());

    Game game;

    game.NameSelection();

    std::string output = mockOutput.str();
    EXPECT_TRUE(output.find("You have chosen to quit. Goodbye.") != std::string::npos);

    std::cin.rdbuf(originalCin);
    std::cout.rdbuf(originalCout);

    
}

TEST(GameTest, NameSelectionInvalidInputTest) {
    std::stringstream mockInput("John\na\n2\n"); // Simulates user entering a name and confirming it
    std::stringstream mockOutput;

    std::streambuf* originalCin = std::cin.rdbuf();
    std::streambuf* originalCout = std::cout.rdbuf();
    

    std::cin.rdbuf(mockInput.rdbuf());
    std::cout.rdbuf(mockOutput.rdbuf());

    Game game;

    game.NameSelection();

    std::string output = mockOutput.str();
    EXPECT_TRUE(output.find("Invalid Input. Enter option again:") != std::string::npos);
    EXPECT_TRUE(output.find("You have chosen to quit. Goodbye.") != std::string::npos);


    std::cin.rdbuf(originalCin);
    std::cout.rdbuf(originalCout);
}




TEST(GameTest, PlayGameTest) {
    // Prepare input stream to simulate both name selection and the initial action in PlayGame
    std::stringstream mockInput;
    mockInput << "John\n1\n"; // Inputs for NameSelection: name entry and confirmation
    mockInput << "y\n"; // Simulate starting a battle immediately in PlayGame

    std::streambuf* originalCin = std::cin.rdbuf();
    std::streambuf* originalCout = std::cout.rdbuf();




    std::stringstream mockOutput;
    std::cin.rdbuf(mockInput.rdbuf());
    std::cout.rdbuf(mockOutput.rdbuf());

    Game game;

    // Call NameSelection first to simulate setting up the player's name
    game.NameSelection();
    

    game.setPlayerPoints(100);

    // Execute the PlayGame method which now operates with a selected name
    game.PlayGame();

    // Validate the outcome
    std::string output = mockOutput.str();
    EXPECT_TRUE(output.find("You have reached 100 points and won the game!!!") != std::string::npos); // Verify the specific output
    
    std::cin.rdbuf(originalCin);
    std::cout.rdbuf(originalCout);
}



TEST(GameTest, BedCheckpointStatsTest) {
    // Prepare input stream to simulate name selection and choosing to print stats
    std::stringstream mockInput;
    mockInput << "John\n1\n"; // Inputs for NameSelection: name entry and confirmation
    mockInput << "s\n"; // Simulates user choosing to print stats in bed_checkpoint


    std::streambuf* originalCin = std::cin.rdbuf();
    std::streambuf* originalCout = std::cout.rdbuf();

    std::stringstream mockOutput;
    std::cin.rdbuf(mockInput.rdbuf());
    std::cout.rdbuf(mockOutput.rdbuf());

    Game game;

    game.NameSelection();
    game.bed_checkpoint();

    // Validate the outcome
    std::string output = mockOutput.str();
    // Fix the check to ensure it correctly verifies the presence of the expected output
    EXPECT_TRUE(output.find("current weapon: stick") != std::string::npos);
    EXPECT_TRUE(output.find("weapons damage: -5") != std::string::npos);
    EXPECT_TRUE(output.find("current health: 20") != std::string::npos);
    EXPECT_TRUE(output.find("current points: 0") != std::string::npos);



    std::cin.rdbuf(originalCin);
    std::cout.rdbuf(originalCout);
}


TEST(GameTest, BedCheckpointPlayTest) {
    // Prepare input stream to simulate name selection and choosing to print stats
    std::stringstream mockInput;
    mockInput << "John\n1\n"; // Inputs for NameSelection: name entry and confirmation
    mockInput << "y\n"; // Simulates user choosing to print stats in bed_checkpoint


    std::streambuf* originalCin = std::cin.rdbuf();
    std::streambuf* originalCout = std::cout.rdbuf();


    std::stringstream mockOutput;
    std::cin.rdbuf(mockInput.rdbuf());
    std::cout.rdbuf(mockOutput.rdbuf());

    Game game;

    game.NameSelection();
    game.bed_checkpoint();

    // Validate the outcome
    std::string output = mockOutput.str();
    // Fix the check to ensure it correctly verifies the presence of the expected output
    EXPECT_TRUE(output.find("You've chosen to battle") != std::string::npos);


    std::cin.rdbuf(originalCin);
    std::cout.rdbuf(originalCout);
}


TEST(GameTest, BedCheckpointQuitTest) {
    // Prepare input stream to simulate name selection and choosing to print stats
    std::stringstream mockInput;
    mockInput << "John\n1\n"; // Inputs for NameSelection: name entry and confirmation
    mockInput << "q\n"; // Simulates user choosing to print stats in bed_checkpoint

    std::streambuf* originalCin = std::cin.rdbuf();
    std::streambuf* originalCout = std::cout.rdbuf();

    std::stringstream mockOutput;
    std::cin.rdbuf(mockInput.rdbuf());
    std::cout.rdbuf(mockOutput.rdbuf());

    Game game;

    // Call NameSelection first to simulate setting up the player's name
    game.NameSelection();

    // Execute the bed_checkpoint method which operates after a name has been set
    game.bed_checkpoint();

    // Validate the outcome
    std::string output = mockOutput.str();
    // Fix the check to ensure it correctly verifies the presence of the expected output
    EXPECT_TRUE(output.find("You have chosen to quit. Goodbye.") != std::string::npos);


    std::cin.rdbuf(originalCin);
    std::cout.rdbuf(originalCout);
}



TEST(GameTest, BattleQuitTest) {
    // Prepare input stream to simulate name selection and choosing to print stats
    std::stringstream mockInput;
    mockInput << "John\n1\n"; // Inputs for NameSelection: name entry and confirmation
    mockInput << "q\n"; // Simulates user choosing to print stats in bed_checkpoint

    std::streambuf* originalCin = std::cin.rdbuf();
    std::streambuf* originalCout = std::cout.rdbuf();


    std::stringstream mockOutput;
    std::cin.rdbuf(mockInput.rdbuf());
    std::cout.rdbuf(mockOutput.rdbuf());

    Game game;

    // Call NameSelection first to simulate setting up the player's name
    game.NameSelection();
    
    // Execute the bed_checkpoint method which operates after a name has been set
    game.battle();

    // Validate the outcome
    std::string output = mockOutput.str();
    // Fix the check to ensure it correctly verifies the presence of the expected output
    EXPECT_TRUE(output.find("you chose the easy way out smh") != std::string::npos);

    std::cin.rdbuf(originalCin);
    std::cout.rdbuf(originalCout);
}

TEST(GameTest, BattleStartTest) {
    // Prepare input stream to simulate name selection and choosing to print stats
    std::stringstream mockInput;
    mockInput << "John\n1\n"; // Inputs for NameSelection: name entry and confirmation
    mockInput << "s\n"; // Simulates user choosing to print stats in bed_checkpoint

    std::streambuf* originalCin = std::cin.rdbuf();
    std::streambuf* originalCout = std::cout.rdbuf();

    std::stringstream mockOutput;
    std::cin.rdbuf(mockInput.rdbuf());
    std::cout.rdbuf(mockOutput.rdbuf());

    Game game;

    // Call NameSelection first to simulate setting up the player's name
    game.NameSelection();
    
    // Execute the bed_checkpoint method which operates after a name has been set
    game.battle();

    // Validate the outcome
    std::string output = mockOutput.str();
    // Fix the check to ensure it correctly verifies the presence of the expected output
    EXPECT_TRUE(output.find("your battle begins now!") != std::string::npos);

    std::cin.rdbuf(originalCin);
    std::cout.rdbuf(originalCout);
}




/*
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/
