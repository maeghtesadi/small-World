#pragma once
#include "Region.h"
#include <vector>
using namespace std;

class Map {
private:

	vector<Region> regions;

public:
	Map();

	Map(vector<Region> regions);

	Region find(Region region);

	vector<Region> getRegions();

	vector<Region>* getRegionsPtr();

	void printMapGraph();

	//test if graph is connected

	void BFS(Region* r, vector<bool>& visited);

	//Map getTranspose();

	bool isConnected();

	//~Map();

};