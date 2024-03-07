#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "../header/Character.hpp"
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
        void battle();
    
    private:
        Player *playerOne=new Player();
        Enemy *enemy=nullptr;
        Point *player_points=new Point();
        Weapon *player_weapon=new Weapon();
};
 #endif