#ifndef CHARACTER_HPP
#define CHARACTER_HPP
using namespace std;

class Character{
    public:
        Character();
        ~Character();

        void getName();
        void setName();
        void getHealth();
        void setHealth();


    private:
       int health;
       string name;

};
 #endif
