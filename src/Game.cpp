#include <iostream>
#include "../header/Game.hpp"
#include "../header/Character.hpp"
#include "../header/Player.hpp"
#include "../header/Enemy.hpp"
#include "../header/dice.hpp"
#include "limits"
#include <vector>
#include <string>

using namespace std;

void Game::StartGame(){
    cout << "Please type a number to select an option: \n" 
	 << "\t1) Play"
	 << "\t2) Exit\n";
    string userInput;

    if(cin >> userInput){

        while (userInput != "1" && userInput != "2") {
            cout << "Invalid Input. Enter option again: ";
            cin >> userInput;
            cout << endl;
        }

        if(userInput == "2"){

            return;  
        } else {

            Intro();

            NameSelection();

            PlayGame();
        }
    }

    return;
}

void Game::Intro(){
    cout << "Welcome to Unlucky Player's Terminal Adventures. You have been transported to a hospital. In this game, you have a terminal cancer! Hooray! Your goal for this game is to beat as many boss as possible and earn 100 points to defeat the cancer!\n"        
         << "\t1) if you would like to enter the game to heal the cancer\n" 
         << "\t2) quit\n\n\n";

    string userInput;
    if(cin >> userInput){

        while (userInput != "1" && userInput != "2") {

            cout << "Invalid Input. Enter option again: ";
            cin >> userInput;
            cout << endl;
        }

        if (userInput == "2") {
            cout << "You die.\n";
            return;
        }
    } 
}

void Game::NameSelection(){
    //name
    cout << "What is your name?\n";
    string userName;
    cin >> userName;
    playerOne = new Player(userName);

    //confirm
    cout << "\n\nAre you sure you would like to continue with the name " << userName << "?\n";
    cout << "Options: \n"
         << "\t1) confirm\n"
         << "\t2) quit\n\n\n";

    string userInput;

    if(cin >> userInput){

        while (userInput != "1" && userInput != "2") {

            cout << "Invalid Input. Enter option again: ";
            cin >> userInput;
            cout << endl;
        }

        if (userInput == "2") {
            cout << "You have chosen to quit. Goodbye.\n\n";
            exit(0);
        } else {
            cout << "You have chosen to confirm. Welcome " << userName << ".\n\n";
        }
    } 
    return;

}

void Game::PlayGame(){
    // intro and stats
    cout << "\n\nYou spawn in the world. You wake up.\n\n"
         << "Stats: \n"
         << "\tClass: Warrior\n"
         << "\tHealth: 20/20\n"
         << "\tAttack: 2\n"
         << "\tDefense: 1\n\n\n";
    // intro to boss
    cout << "You look out your bedroom window and realize you have been transported to a different world.\n"
         << "You get out of bed...\n"
         << "As you are about to walk out of your room, you encounter your first enemy...\n"
         << "Your first enemy is a housefly. Defeat it to gain points to cure your illness\n\n\n";
    
    //rules to battling
    cout<<"In battle you will choose a number 1-6 and the Enemy will roll a dice\n"
        <<"if the number you choose is less than the one the enemy rolled he gets to attacks and vice versa\n\n\n";

    while (player_points->getPoint() < 100) {
        bed_checkpoint();
        battle();
    }
    cout << "You have reached 100 points and won the game!!!\n"
         << "After enduring countless chemotherapy sessions, braving the trials of the Bosses, you finally stand victorious at the Cancer Treatment Center.\n"
         << "Though the road was tough and the challenges many, you emerged stronger, wiser, and filled with hope for the future. The sun shines brighter, the colors seem more vivid, and you know that you are unstoppable.\n";
}


void Game::bed_checkpoint(){

    cout<<"You have spawned into your bed\n\n";
    cout<<"Options:\n"
        <<"\ts) print your stats\n"
        <<"\ty) start battle\n"
        <<"\tq) quit\n\n";
    
    char buttonOption;

    if (cin >> buttonOption){
        while (buttonOption!='s' && buttonOption!='y' && buttonOption!='q'){

            cout << "Invalid Input. Enter option again: ";
            cin >> buttonOption;
            cout << endl;
        }

        if (buttonOption=='s'){

            printUserStats();
        } else if (buttonOption == 'q'){

            cout << "You have chosen to quit. Goodbye.\n";
            exit(0);
        } else {

            cout<<"You've chosen to battle"<<endl;
            battle();
        }
    }

    return;
} 

void Game::printUserStats(){

    cout<<"Your current stats: "<<endl;
    
    cout<<"\tWeapon and weapons damage: "<<endl<<endl 
        <<"\tcurrent weapon: "<<player_weapon->getWeapon()<<endl
        <<"\tweapons damage: "<<player_weapon->getWeaponDamage()<<endl<<endl;
    
    cout<<"\tcurrent health:"<<playerOne->getHealth()<<endl<<endl;

    cout<<"\tcurrent points: "<<player_points->getPoint()<<endl;

    return;
}


void Game::battle(){

    char choice;//ask if player wants to flee or fight 
    vector<string> enemyNames = {"Viper", "Shadow", "Doom", "Nightmare", "Darklord"};
    Enemy *enemy = new Enemy();
    enemy->setName(enemy->getRandomEnemyName(enemyNames));
    enemy->setHealth(enemy->randomInRange(20, 50));
    // enemy = new Enemy(enemy.getRandomEnemyName(enemyNames));
    // // enemy.setName(enemy.getRandomEnemyName(enemyNames));
    // enemy.setHealth(enemy.randomInRange(20, 50));  

    //enemy=new Enemy("housefly");    
    
    cout<<"you are now fighting "<<enemy->getName() << "\n"
        <<"\tq) flee by pressing but you will die for being a coward!\n"
        <<"\ts) start battle\n\n";

    if (cin >> choice){
        while (choice!='s' && choice!='y' && choice!='q'){

            cout << "Invalid Input. Enter option again: ";
            cin >> choice;
            cout << endl;
        }

        if (choice == 'q'){

            cout<<"you chose the easy way out smh\n";
            exit(0);
        } else {

            cout<<"your battle begins now!\n\n";
        }
    }


    while(enemy->getHealth()>0){//allows for player to keep fighting until he defeats the boss
        Dice *action=new Dice();//an intance of the dice object to see players action
        
        cout<<"\n\n\npress x to roll the dice to see if you have to fight or defend"<<endl;
        char button;
        cin>>button;

        int playerRoll = action->rollDice();//player roll
	    
        if (button=='x'){
            cout<<"\n\nYou rolled "<<playerRoll<< " VS ";
        }
        
        int enemyRoll=action->rollDice();
        cout<<enemy->getName()<<" rolled "<<enemyRoll<<"'\n\n'";
        

        if (playerRoll > enemyRoll){//if user choice is greater then he has a chance to attack
            
            cout<<"you now get to attack!!!!!!"<<endl;
            if (action->rollDice()%2==0){//second condition just to see if enemy blocked or not
                player_weapon->weaponAttack(enemy);
                cout<<"your attack hit "<<enemy->getName()<<endl<<endl
                    <<"your opponent is now down "<<player_weapon->getWeaponDamage()<<" hp from attack\n\n"
                    <<"he now has "<<enemy->getHealth()<<" health"<<endl;
            }
            else{
                cout<<"Oops your attack was blocked\n\n";
            }
        }

        else if(enemyRoll>playerRoll){//if first condition not met then the enemy attacks
            cout<<"you chose wrong sadly now try and dodge!"<<endl;
            cout<<enemy->getName()<<" is now going to attack\n";
            if (action->rollDice()%2==0){ //if modulo 2 then you dodge
                cout<<"Nice! you dodged his attack\n\n";
            }

            else{//you get hit by the boss
                playerOne->damageDone(-2);
                cout<<"Oh no you got hit "<<"you now have "<<playerOne->getHealth()<<" health left\n\n";
            }
        }
        
        else{//both players roll same number
            cout<<" woah you guys got same number nothing happens!!!"<<endl;
        }

        if (playerOne->getHealth()<=0){
            cout<<"OH YOU DEAD LOL\n";
            bed_checkpoint();
            //later add a way to go back to bed checkpoint
        }
        
	delete action;

    }

    //player defeated the boss
    cout<<"\n\n\nCongrats you have defeated the Boss!!!!!\n"<<'\n'
    <<"Because of your victory you will be rewarded 20 points!!!!!\n\n\n";
    
    player_points->addPoint(20);//reward is 20 pts
    player_weapon->change_weapon(player_points);
    cout<<"Congrats your new current weapon is now"<<player_weapon->getWeapon()<<endl; 

    
    delete enemy;
}       
//\n
