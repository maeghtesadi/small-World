#include "DiceRollingFacility.h"
#include <ctime>
#include <iostream>

using namespace std;

DiceRollingFacility::DiceRollingFacility() {

}

int DiceRollingFacility::rollDice() { //random generator for the dice
	int r = 0;
	srand((unsigned)time(0));
	for (int i = 1; i <= 3; i++) {
		r = rand() % 3;
	}

	return r;
}