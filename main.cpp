#include <iostream>
#include "header/Player.hpp"  

int main() {
    Player player("Alice");

    // Displaying the initial state
    std::cout << "Initial Health: " << player.getHealth() << std::endl;
    std::cout << "Initial Name: " << player.getName() << std::endl;

    // Modifying the character's attributes
    player.addHealth(5);
    player.setName("Bob");

    // Displaying the updated state
    std::cout << "Updated Health: " << player.getHealth() << std::endl;
    std::cout << "Updated Name: " << player.getName() << std::endl;

    // Demonstrate the damageDone function
    player.damageDone(3);
    std::cout << "Health after damage: " << player.getHealth() << std::endl;

    return 0;
}
