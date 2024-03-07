#include <iostream>
#include "../header/Game.hpp"
#include "../header/Character.hpp"
#include "../header/Player.hpp"
#include "../header/Enemy.hpp"
#include "../header/dice.hpp"
#include "limits"


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
         << "Your first enemy is a housefly. Defeat it to gain points to cure your illness\n\n";
    
    //rules to battling
    cout<<"In battle you will choose a number 1-6 and the Enemy will roll a dice\n"
        <<"if the number you choose is less than the one the enemy rolled he gets to attacks and vice versa\n\n";
    enemy=new Enemy("housefly");
    bed_checkpoint();
    //battle();//delete later       
}

void Game::battle(){
    
    char choice;//ask if player wants to flee or fight 
    
    cout<<"you are now fighting "<<enemy->getName()
        <<" you can flee by pressing 'q' but you will die for being a coward!\n"
        <<"if you want to fight press any other character\n\n";


    
    cin>>choice;
    cin.clear();//flush buffer
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (choice=='q'){
        //player_points->addPoint(-1*player_points->getPoint());
        cout<<"you chose the easy way out smh\n";
        exit(1);
    }
    else{
        cout<<"your battle begins now!\n\n";
       
    }/**/

    while(enemy->getHealth()>0){//allows for player to keep fighting until he defeats the boss
        Dice *action=new Dice();//an intance of the dice object to see players action
        
        cout<<"press x to roll the dice to see if you have to fight or defend"<<endl;
        char button;
        cin>>button;

        //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


        int playerRoll=action->rollDice();
        if (button=='x'){
            cout<<"you rolled "<<playerRoll<<endl<<endl;
        }
        cout<<enemy->getName()<< "will roll now"<<endl;
        int enemyRoll=action->rollDice();

        cout<<enemy->getName()<<" rolled "<<enemyRoll<<'\n';

        

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
                cout<<"Nice! you doged his attack\n\n";
            }

            else{//you get hit by the boss
                playerOne->damageDone(-2);
                cout<<"Oh no you got hit "<<"you now have "<<playerOne->getHealth()<<" health left\n\n";
            }
        }
        else{
            cout<<" woah you guys got same number nothing happens!!!"<<endl;
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
    cout<<"congrats you have defeated the Boss!!!!!\n"
    <<'\n'
    <<"Because of your victory you will be rewarded 4 points!!!!!";
    player_points->addPoint(4);
    cout<<"you now have "<<player_points->getPoint()<<" points"<<endl;
    
}


void Game::bed_checkpoint(){
    cout<<"You have spawned into your bed"<<endl;
     
    char buttonOption;
    cin>>buttonOption; 
    cin.clear();//flush buffer
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    cout<<"if you want to check your current stats press s"<<endl
        <<"else press any other character"<<endl;

    if (buttonOption=='s'){
        cout<<"these are your current stats"<<endl;
        
        cout<<"Weapon and weapons damage:"<<endl<<endl 
            <<"current weapon: "<<player_weapon->getWeapon()<<endl
            <<"weapons damage: "<<player_weapon->getWeaponDamage()<<endl<<endl;
        
        cout<<"current health:"<<playerOne->getHealth()<<endl<<endl;

        cout<<"current points: "<<player_points->getPoint()<<endl;

    }
    
    cout<<"Do you want to go into battle?"<<endl;
    cout<<"press y for yes or n for no"<<endl;
    
    char battleOption;
    cin>>battleOption;
    if (battleOption=='n'){
        cout<<"ok"<<endl;
        exit(1);
    }
    else if(battleOption=='y'){
        battle();
        //exit(1);


    }
    else{
        exit(1);
    }

    
}        
//\n