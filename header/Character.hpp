#pragma once 
#include <string>

class Character {
public:
    Character();
    Character(std::string name);
    virtual ~Character(); // Make destructor virtual for base class


        string getName()const;
        void setName(string name);
        int getHealth();
        void addHealth(int health);
        void setHealth(int health);


    private:
       int _health;
       string _name;
}
 #endif
