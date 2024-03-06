#include <iostream>
#include "../header/Game.hpp"
#include "../header/Character.hpp"

using namespace std;

void Game::StartGame(){
    cout << "Please type a number to select an option...\n" << "1 for Play, 2 for Exit\n";
    string userInput;
    if(cin >> userInput){
        if(userInput == "1"){
            Intro();        
        }
        else{
            return;
        }
    }
    else{
        cout << "Invalid Input. Exiting\n";
        exit(1);
    }
}

void Game::Intro(){
    cout << "Welcome to Unlucky Player's Terminal Adventures. You have been transported to a hospital. In this game, you have a terminal cancer! Hooray! Your goal for this game is to beat as many boss as possible and earn 100 points to defeat the cancer!\n"
         << "Press 1 if you would like to enter the game to heal the cancer, otherwise press 2.\n";

    string userInput;
    if(cin >> userInput){
        if(userInput == "1"){
            cout << "You choose to fight the bosses to cure your cancer. Good luck.\n";
            NameSelection();        
        }
        else{
            cout << "You die.\n";
            return;
        }
    } 
    else{
        cout << "Invalid Input. Exiting\n";
        exit(1);
    }
}

void Game::NameSelection(){
    //name
    cout << "What is your name?\n";
    string userName;
    cin >> userName;
    Character playerOne = new Character(userName);

    //confirm
    cout << "Are you sure you would like to continue with the name " << userName << "?\n";
    cout << "Press 1 to confirm, and anything else to quit\n";
    string userInput;
    if(cin >> userInput){
        if(userInput == "1"){
            cout << "You have chosen to confirm. Welcome " << userName << ".\n";
            PlayGame();
        }
        else{
            cout << "You have chosen to quit. Goodbye.\n";
            return;
        }
    }
    else{
        cout << "Invalid input, exiting game.\n";
        return;
    }
}

void PlayGame(){
    // intro and stats
    cout << "You spawn in the world. You wake up.\n"
         << "Stats: \n"
         << "Class: Warrior\n"
         << "Health: 20/20\n"
         << "Attack: 2\n"
         << "Defense: 1\n";
    // intro to boss
    cout << "You look out your bedroom window and realize you have been transported to a different world.\n"
         << "You get out of bed...\n"
         << "As you are about to walk out of your room, you encounter your first enemy...\n"
         << "Your first enemy is a housefly. Defeat it to gain points to cure your illness\n";    
}
    