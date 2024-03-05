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
            PlayGame();        
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

void Game::PlayGame(){
    //name
    cout << "What is your name?\n";
    string userName;
    cin >> userName;
    Character playerOne = new Character(userName);

}