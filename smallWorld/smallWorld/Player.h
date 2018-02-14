#pragma once
#include "Coin.h"
#include "Region.h"
#include <vector>
#include <string>


using namespace std;

class Player {

private:
	//a number to identify players
	int id; 

	vector<Region*>* regions;

	vector<Coin*>* coins;

	string summarySheet;

	//game tokens

	//dice rolling facility

public:

	Player();

	void picks_race();

	void conquers();

	void scores();

	void addRegions(Region* region);

	void removeRegions(Region* region);

	vector<Region*>* getRegions();

	void addCoin(Coin* coin);

	void removeCoin(Coin* coin, int value_of_coin);

	vector<Region*>* getCoins();

	string getSummarySheet();

	void setSummarySheet(string summary);

	void appendSummarySheet(string summary);
};