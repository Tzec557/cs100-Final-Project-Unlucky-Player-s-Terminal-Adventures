#pragma once

#include "../header/Character.hpp"
#include "../header/Player.hpp"
#include "../header/Enemy.hpp"
#include "../header/Point.hpp"
#include "../header/weapon.hpp"
#include "../header/dice.hpp"
using namespace std;




class Game{
    public:
        virtual ~Game(){
            if (playerOne != nullptr){
                delete playerOne;
                playerOne=nullptr;
            }
            /*if (enemy !=nullptr){ 
                delete enemy; 
                enemy=nullptr;
            }
            */
            if (player_points !=nullptr){   
                delete player_points;
                player_points=nullptr;
            }
            
            if (player_weapon != nullptr){  
                delete player_weapon;
                player_weapon=nullptr;
            }
        }
        virtual void StartGame();
        virtual void Intro();
        virtual void NameSelection();
        virtual void PlayGame();
	virtual void setPlayerPoints(int);
	virtual void printUserStats();
        virtual void battle();
        virtual void bed_checkpoint();
    
    private:
        Player *playerOne=nullptr;
        Enemy *enemy=nullptr;
        Point *player_points=new Point();
        Weapon *player_weapon=new Weapon();
	    bool isGameRunning = true;
};
