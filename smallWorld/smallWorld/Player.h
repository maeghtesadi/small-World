#pragma once
#include "Region.h"
#include <vector>


using namespace std;

class Player {

private:
	//a number to identify players
	int id; 

	vector<Region*>* regions;

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


};