#pragma once
#include <vector>

using namespace std;

class DiceRollingFacility
{
private:
	
	int number_of_rolls;

	//0index is for 1, 1index is for 2... 
	//3,4 and 5 indices are for black dice values 
	vector<int> number_of_Getting_each_value;

public:
	
	DiceRollingFacility();

	int rollDice();

	//console output
	void printPercentage_of_Getting_each_value();

	void testDice();
};

