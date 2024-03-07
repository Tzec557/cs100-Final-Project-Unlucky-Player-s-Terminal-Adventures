#include <iostream>
#include "../header/Game.hpp"
#include "../header/Character.hpp"
#include "../header/Player.hpp"
#include "../header/Enemy.hpp"
#include "../header/dice.hpp"


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
    playerOne = new Player(userName);

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

void Game::PlayGame(){
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
    battle();//delete later       
}

void Game::battle(){
    
    enemy=new Enemy();//look into changing this later but intialize enemy
    
    char choice;//ask if player wants to flee or fight 
    
    cout<<"you are now fighting "<<enemy->getName()
        <<" you can flee by pressing 'q' but you will die!\n"
        <<"if you want to fight press any other character\n";
    
    cin>>choice;
    if (choice=='q'){
        //player_points->addPoint(-1*player_points->getPoint());
        cout<<"you chose the easy way out\n";
        exit(1);
    }
    else{
        cout<<"your battle begins now!\n";
    }/**/
    while(enemy->getHealth()>0){//allows for player to keep fighting until he defeats the boss
        Dice *action=new Dice();//an intance of the dice object to see players action
        
    
        if (action->rollDice()%2==0){//if number modulo 2 is zero then attack
            if (action->rollDice()%2==0){
                player_weapon->weaponAttack();
                cout<<"you hit the boss\n"
                    <<"Boss took "<<player_weapon->getWeaponDamage()<<" points in damage\n";
            }

            else{
                cout<<"Boss blocked your attack\n";
            }
        }

        else{//if first condition not met then the enemy attacks
            cout<<"Boss is now going to atttack\n";
            if (action->rollDice()%2==0){ //if modulo 2 then you dodge
                cout<<"Nice! you doged his attack\n";
            }

            else{//you get hit by the boss
                playerOne->damageDone(-15);
                cout<<"Oh no you got hit "<<"you now have "<<playerOne->getHealth()<<" health left\n";
            }
        }

        if (playerOne->getHealth()<=0){
            cout<<"OH YOU DEAD LOL\n";
            delete action;
            exit(1);//later add a way to go back to bed checkpoint
        }
        if (enemy->getHealth()<=0){
            delete action;
        }
    }
    cout<<"congrats you have defeated the Boss!!!!!\n";
    
}

//\n