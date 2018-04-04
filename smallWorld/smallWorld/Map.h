#pragma once
#include "Region.h"
#include "Observer.h"
#include "Subject.h"
#include <vector>
using namespace std;

class Map : public Subject {
private:

	vector<Region*> regions;
	
	int nb_of_turns;

public:
	Map();

	Map(vector<Region*> regions);

	Region find(Region region);

	vector<Region*> getRegions();

	void setRegions(vector<Region*> regions);

	vector<Region*>* getRegionsPtr();

	void printMapGraph();

	void setNb_of_turns(int turns);

	int getNb_of_turns();

	void changeRegionOwnerId(int regionId, int newOwnerId);

	//test if graph is connected

	void BFS(Region* r, vector<bool>& visited);

	//Map getTranspose();

	bool isConnected();

	//~Map();

};