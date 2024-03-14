#include <iostream>
#include "header/Enemy.hpp"  // Assuming the correct path to Enemy.hpp
#include "header/Player.hpp"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>


int main() {
    vector<string> enemyNames = {"Enemy1", "Enemy2", "Enemy3", "Enemy4", "Enemy5"};
    // Creating an Enemy object
    Enemy enemy;
    enemy.setName(enemy.getRandomEnemyName(enemyNames));
    enemy.setHealth(enemy.randomInRange(20, 50));  
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
