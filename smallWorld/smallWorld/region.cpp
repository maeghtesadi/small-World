#include "Region.h"

Region::Region()
{

}

Region::Region(int id, int token, vector<Region> neigborRegions)
{
	this->id = id;
	this->token = token;
	this->neigborRegions = neigborRegions;
}

void Region::setId(int token)
{
	this->id = id;
}

int Region::getId()
{
	return id;
}

void Region::setToken(int token)
{
	this->token = token;
}

int Region::getToken()
{
	return token;
}

void Region::setNeigborRegions(vector<Region> neigborRegions)
{
	this->neigborRegions = neigborRegions;
}

void Region::addNeigborRegions(Region region)
{
	neigborRegions.push_back(region);
}

void Region::removeNeigborRegions(Region region)
{
	for (int i = 0; i < neigborRegions.size; i++)
	{
		if (neigborRegions[i].id == region.getId())
		{
			neigborRegions.erase(neigborRegions.begin() + i);
		}
	}
}

vector<Region> Region::getNeigborRegions()
{
	return neigborRegions;
}