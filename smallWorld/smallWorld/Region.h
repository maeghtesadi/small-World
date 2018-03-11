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
	
	string type;

	string symbol;

	bool borderRegion;

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

	

public:
	Region();

	Region(int id, int token);

	Region(int id, int token, Point point);
	
	Region(int id, int token, string type, int owner_id, string symbol, bool borderRegion, Point point);

	void setId(int token);

	int getId();

	void setOwner_id(int owner_id);

	int getOwner_id();

	void setToken(int token);

	int getToken();

	void setType(string type);

	string getType();

	void setSymbol(string symbol);

	string getSymbol();

	void setBorderRegion(bool borderRegion);

	bool getBorderRegion();

	void setNeigborRegions(vector<Region*> neigborRegions);

	void addNeigborRegions(Region* region);

	void removeNeigborRegions(Region* region);

	vector<Region*> getNeigborRegions();

	void setGamePiece(vector<GamePiece*> neigborRegions);

	void addGamePiece(GamePiece* region);

	void removeGamePiece(GamePiece* region);

	vector<GamePiece*> getGamePieces();

	void printNeigbors();
};