#ifndef CHARACTER_HPP
#define CHARACTER_HPP
using namespace std;

class Character{
    public:
        Character(string name);
        ~Character();

        void getName();
        void setName(string name);
        void getHealth();
        void addHealth(int health);


    private:
       int _health;
       string _name;

};
 #endif
