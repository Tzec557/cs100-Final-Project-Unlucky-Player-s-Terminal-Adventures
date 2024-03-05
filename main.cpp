#include <iostream>
#include "header/Player.hpp"  

int main() {
    Player player;

    // Displaying the initial state
    cout << "Initial Health: " << player.getHealth() << endl;
    cout << "Initial Name: " << player.getName() << endl;

    // Modifying the character's attributes
    player.addHealth(5);
    player.setName("Bob");

    // Displaying the updated state
    cout << "Updated Health: " << player.getHealth() << endl;
    cout << "Updated Name: " << player.getName() << endl;

    // Demonstrate the damageDone function
    player.damageDone(-3);
    cout << "Health after damage: " << player.getHealth() << endl;

    return 0;
}
