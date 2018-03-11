
#include "stdafx.h"
#include "Region.h"
#include <iostream>

Region::Region()
{

}

Region::Region(int id, int token) : Region() {
	this->id = id;
	this->token = token;
}

Region::Region(int id, int token, Point point) : Region(id, token)
{
	this->point = point;
}

Region::Region(int id, int token, string type, int owner_id, string symbol, bool borderRegion, Point point)
{
	this->id = id;
	this->token = token;
	this->type = type;
	this->owner_id = owner_id;
	this->symbol = symbol;
	this->borderRegion = borderRegion;
	this->point = point;
}

void Region::setId(int token)
{
	this->id = token;
}

int Region::getId()
{
	return this->id;
}

void Region::setToken(int token)
{
	this->token = token;
}

int Region::getToken()
{
	return token;
}

void Region::setNeigborRegions(vector<Region*> neigborRegions)
{
	this->neigborRegions = neigborRegions;
}

void Region::addNeigborRegions(Region* region)
{
	//pushing the address to the address container
	neigborRegions.push_back(region);
}

void Region::removeNeigborRegions(Region* region)
{
	for (int i = 0; i < neigborRegions.size(); i++)
	{
		if (neigborRegions[i]->id == region->getId())
		{
			neigborRegions.erase(neigborRegions.begin() + i);
		}
	}
}

vector<Region*> Region::getNeigborRegions()
{
	return neigborRegions;
}

void Region::printNeigbors() 
{
	std::cout << "my region id is " << this->id << " and my neigbor's ids are: " << endl;
	for (int i = 0; i < neigborRegions.size(); i++)
	{
		std::cout << neigborRegions[i]->getId() << endl;
	}
}


