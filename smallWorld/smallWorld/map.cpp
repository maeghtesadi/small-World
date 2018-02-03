#include "Map.h"

Map::Map() 
{

}

Map::Map(vector<Region> regions)
{
	this->regions = regions;
}

Region Map::find(Region region)
{
	for (int i = 0; i < regions.size; i++)
	{
		if (regions[i].getId() == region.getId())
		{
			return regions[i];
		}
	}
}