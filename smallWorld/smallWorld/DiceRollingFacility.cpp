#include "stdafx.h"
#include "DiceRollingFacility.h"
#include <chrono>
#include <random>
#include <iostream>

using namespace std;

DiceRollingFacility::DiceRollingFacility() {
	number_of_Getting_each_value = { 0,0,0,0,0,0 };
	number_of_rolls = 0;
	srand(time(0));
}

int DiceRollingFacility::rollDice() { //random generator for the dice
	
	int value_of_dice;
	
	value_of_dice = (rand() % 6) + 1;  //it will generate numbers between 0 - 5, we add  + 1 so that the numbers wouldn't be zero based
	
	//unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	//std::default_random_engine generator;
	//std::uniform_int_distribution<int> distribution(1, 6);
	//int value_of_dice = distribution(generator);




	number_of_rolls++; //increment number of rolls
	number_of_Getting_each_value[value_of_dice - 1]++;

	//make sure 4,5,6 is never returned 
	if (value_of_dice == 4 || value_of_dice == 5 || value_of_dice == 6)
	{
		value_of_dice = 0;
	}

	return value_of_dice;
}

void DiceRollingFacility::printPercentage_of_Getting_each_value() {
	int devider = number_of_rolls;
	if (devider == 0)
	{
		devider = 1;
	}

	cout << "values 4,5,6 represent the 3 blanc values on the dice" << endl;
	cout << "number of die rolled is " << number_of_rolls << endl;
	for (int i = 0; i < number_of_Getting_each_value.size(); i++)
	{
		cout << "Percentage of " << (i + 1) << " is " << (double)number_of_Getting_each_value[i] / (double)number_of_rolls << endl;
	}
}

void DiceRollingFacility::testDice() {
	cout << "testing dice 5 times:" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int i = 0; i < 100; i++)
		{
			cout << rollDice() << " ";
		}
		cout << endl;
		printPercentage_of_Getting_each_value();

		// erase test values
		number_of_Getting_each_value = { 0,0,0,0,0,0};
		number_of_rolls = 0;
	}

}