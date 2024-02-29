#include <iostream>
#include "../header/dice.hpp"

using namespace std;

Dice::Dice() {

	result = 0;
}


int
Dice::rollDice(){

	int dice_result = rand() % 6 + 1;
	this->result = dice_result
	return dice_result;
}
