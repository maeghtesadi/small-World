#pragma once

#include <vector>

using namespace std;

class Region
{
private:

	//id of the region
	int id;

	//token value of the region 
	int token;

	// neigboring regions
	vector<Region> neigborRegions;

public:
	Region();

	Region(int id, int token, vector<Region> neigborRegions);

	void setId(int token);

	int getId();

	void setToken(int token);

	int getToken();

	void setNeigborRegions(vector<Region> neigborRegions);

	void addNeigborRegions(Region region);

	void removeNeigborRegions(Region region);

	vector<Region> getNeigborRegions();

};