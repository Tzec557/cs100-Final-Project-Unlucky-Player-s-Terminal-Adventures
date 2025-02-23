#ifndef CHARACTER_HPP
#define CHARACTER_HPP
using namespace std;
#include <string> 

class Character{
    public:
        Character();
        Character(string name);
        ~Character();

        string getName() const;
        void setName(string name);
        int getHealth() const;
        void addHealth(int health);
        void setHealth(int health);


    private:
       int _health;
       string _name;

};
 #endif