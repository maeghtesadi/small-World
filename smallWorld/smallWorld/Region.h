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

	//the player who controls this region
	int owner_id;

	// neigboring regions
	vector<Region*> neigborRegions; //veken said store pointers //claudia says all object instance variables should be pointers

	//pixel values on the picture
	int x_pos;
	int y_pos;

public:
	Region();

	Region(int id, int token, vector<Region*> neigborRegions);

	Region(int id, int x_pos, int y_pos, int token);

	Region(int id, int x_pos, int y_pos, int token, vector<Region*> neigborRegions);

	void setId(int token);

	int getId();

	void setToken(int token);

	int getToken();

	void setNeigborRegions(vector<Region*> neigborRegions);

	void addNeigborRegions(Region* region);

	void removeNeigborRegions(Region* region);

	vector<Region*> getNeigborRegions();

	void printNeigbors();

};