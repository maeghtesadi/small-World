
#include "stdafx.h"
#include "Map.h"
#include <list>

Map::Map() 
{

}

Map::Map(vector<Region*> regions)
{
	this->regions = regions;
}

Region Map::find(Region region)
{
	for (int i = 0; i < regions.size(); i++)
	{
		if (regions.at(i)->getId() == region.getId())
		{
			return *regions[i];
		}
	}
}

int Map::getNb_of_turns() {

	return nb_of_turns;
}

void Map::setNb_of_turns(int turns) {

	this->nb_of_turns = turns;
}

vector<Region*> Map::getRegions() {

	return regions;
}

vector<Region*>* Map::getRegionsPtr() {

	return &regions;
}

void Map::printMapGraph() {
	for (int i = 0; i < regions.size(); i++)
	{
		regions.at(i)->printNeigbors();
	}
}

void Map::BFS(Region* r, vector<bool>& visited) {
	
	list<Region*> tempRegions;
	//vector<Region*>::iterator i;
	//visited[r->getId()-1] = true; //because region id starts from 1 not 0
	visited[r->getId() - 1] = true;
	tempRegions.push_back(r);
	Region* temp;
	while (!tempRegions.empty())
	{
		temp = tempRegions.front();
		tempRegions.pop_front();
		for (int i = 0; i < temp->getNeigborRegions().size(); i++)
		{
			if (!visited[temp->getNeigborRegions()[i]->getId()-1])
			{
				visited[temp->getNeigborRegions()[i]->getId() - 1] = true;
				tempRegions.push_back(temp->getNeigborRegions()[i]);
			}
		}
	}

}

//Map Map::getTranspose() {
//	/*map t(v);
//	for (int v = 0; v < v; v++)
//	{
//		list<int>::iterator i;
//		for (i = adj[v].begin(); i != adj[v].end(); ++i)
//		{
//			g.adj[*i].push_back(v);
//		}
//	}
//	return t;*/
//}

bool Map::isConnected() {
	int temp = regions.size();
	vector<bool> visited;
	for (int i = 0; i < regions.size(); i++)
		visited.push_back(false);
	BFS(regions[0], visited);
	for (int i = 0; i < regions.size(); i++)
		if (visited[i] == false)
			return false;
	return true;

}

//Map::~Map()
//{
//	for (int i = 0; i < regions.size(); i++)
//	{
//		delete &regions[i];
//	}
//}