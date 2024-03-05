#include <iostream>
#include "header/Enemy.hpp"  // Assuming the correct path to Enemy.hpp

int main() {
    // Creating an Enemy object
    Enemy enemy;

    // Displaying the initial state
    cout << "Initial Health: " << enemy.getHealth() << endl;
    cout << "Initial Name: " << enemy.getName() << endl;

    // Modifying the enemy's attributes
    enemy.addHealth(5);
    enemy.setName("Evil Boss");

    // Displaying the updated state
    cout << "Updated Health: " << enemy.getHealth() << endl;
    cout << "Updated Name: " << enemy.getName() << endl;

    // Demonstrate the damageTaken function
    enemy.damageTaken(-3);
    cout << "Health after damage: " << enemy.getHealth() << endl;

    return 0;
}
