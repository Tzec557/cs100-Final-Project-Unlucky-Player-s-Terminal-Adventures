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
        ~Game(){
            delete playerOne;
            delete enemy;
            delete player_points;
            delete player_weapon;   
        }
        void StartGame();
        void Intro();
        void NameSelection();
        void PlayGame();
	void printUserStats();
        void battle();
        void bed_checkpoint();
    
    private:
        Player *playerOne=nullptr;
        Enemy *enemy=nullptr;
        Point *player_points=new Point();
        Weapon *player_weapon=new Weapon();
};
