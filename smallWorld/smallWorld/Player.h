#pragma once
#include "Coin.h"
#include "Region.h"
#include "DiceRollingFacility.h"
#include "Race.h"
#include <vector>
#include <string>
#include "Strategy.h"
#include "Subject.h"

using namespace std;

class Player: public Subject {

private:
	//a number to identify players
	int id; 

	vector<Region*>* regions;

	vector<Coin*>* coins;

	string summarySheet;

	vector<Race*>* races;

	DiceRollingFacility* die;

	Strategy *strategy;

public:

	Player();

	void picks_race(Race* race);

	void conquers();

	int scores();

	void addRegions(Region* region);

	void removeRegions(Region* region);

	vector<Region*>* getRegions();

	void addCoin(Coin* coin);

	void removeCoin(int value_of_coin);

	vector<Coin*>* getCoins();

	int rollDice();

	string getSummarySheet();

	void setSummarySheet(string summary);

	void appendSummarySheet(string summary);

	void addRaces(Race* region);

	void removeRaces(Race* region);

	vector<Race*>* getRaces();

	void setStrategy(Strategy *newStrategy);

	int executeStrategy(Map* gameBoard, int raceToken, int maxRaceToken, int playerId);


	~Player();
};

//implementing strategy pattern 