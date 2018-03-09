#pragma once

#include <vector>
#include "Point.h"
#include "GamePiece.h"

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
	
	/// <summary>
	/// The game pieces
	/// </summary>
	vector<GamePiece*> gamePieces;

	// neigboring regions
	vector<Region*> neigborRegions; //veken said store pointers //claudia says all object instance variables should be pointers
									
	/// <summary>
	/// The x, y pixel coordinates on the picture
	/// </summary>
	Point point;

	Region(int id, int token);

public:
	Region();

	Region(int id, int token, Point point);

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