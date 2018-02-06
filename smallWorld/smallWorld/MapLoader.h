#pragma once
#include <fstream>
#include "Region.h"
#include "Map.h"

using namespace std;

class MapLoader
{
private:
	Map map;
	string file;
	string pictureLocation;

	//to store the nodes and edges
	vector<vector<int>> edges;

public:
	MapLoader();

	MapLoader(string file);

	//read file and make a map
	void setMap(string file);
	
	void setMap();

	void setMapGraph();

	Map getMap();
	
	string getFile();

	string getPictureLocation();

	vector<vector<int>> getEdges();

};
