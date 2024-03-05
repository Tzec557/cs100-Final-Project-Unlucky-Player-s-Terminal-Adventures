#include <iostream>
#include "header/Character.hpp"

int main() {
    // Creating a Character object with a name
    Character player("John Doe");

    // Displaying the initial state
    std::cout << "Initial Health: " << player.getHealth() << std::endl;
    std::cout << "Initial Name: " << player.getName() << std::endl;

    // Modifying the character's attributes
    player.addHealth(5);
    player.setName("Jane Doe");

    // Displaying the updated state
    std::cout << "Updated Health: " << player.getHealth() << std::endl;
    std::cout << "Updated Name: " << player.getName() << std::endl;

    return 0;
}
