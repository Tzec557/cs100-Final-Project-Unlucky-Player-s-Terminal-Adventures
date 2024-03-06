#pragma once 
#include <string>

class Character {
public:
    Character();
    Character(std::string name);
    virtual ~Character(); // Make destructor virtual for base class

    std::string getName() const; // Mark getters as const
    void setName(std::string name);
    int getHealth() const;
    void addHealth(int health);

protected:
    int _health;
    std::string _name;
};
