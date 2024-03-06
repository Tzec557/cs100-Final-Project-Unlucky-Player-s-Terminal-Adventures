#include <iostream>
#include "header/Character.hpp"

int main() {
    // Creating a Character object with a name
    Character player("John Doe");
    Character player1 = Character("Alice");
    string userName = "A";
    Character playerOne =  Character(userName);

    // Displaying the initial state
    std::cout << "Initial Health: " << player.getHealth() << std::endl;
    std::cout << "Initial Name: " << player.getName() << std::endl;

     std::cout << "Initial Name: " << playerOne.getName() << std::endl;

    std::cout << "Initial Health: " << player1.getHealth() << std::endl;
    std::cout << "Initial Name: " << player1.getName() << std::endl;
    // Modifying the character's attributes
    player.addHealth(5);
    player.setName("Jane Doe");

    player1.addHealth(-5);
    player.setName("Jan");

    // Displaying the updated state
    std::cout << "Updated Health: " << player.getHealth() << std::endl;
    std::cout << "Updated Name: " << player.getName() << std::endl;

    std::cout << "Updated Health: " << player1.getHealth() << std::endl;
    std::cout << "Updated Name: " << player1.getName() << std::endl;
    return 0;
}
