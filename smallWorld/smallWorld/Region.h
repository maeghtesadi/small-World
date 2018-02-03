#pragma once

#include <vector>

using namespace std;

class Region
{
private:

	int id;

	int token;

	vector<Region> neigborRegions;

public:
	Region();

	Region(int id, int token, vector<Region> neigborRegions);

	void setId(int token);

	int getId();

	void setToken(int token);

	int getToken();

	void addNeigborRegions(Region region);

	void removeNeigborRegions(Region region);

	vector<Region> getNeigborRegions();

};