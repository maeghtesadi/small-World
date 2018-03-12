
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

void Region::setOwner_id(int owner_id)
{
	this->owner_id = owner_id;
}

int Region::getOwner_id()
{
	return this->owner_id;
}

void Region::setType(string type)
{
	this->type = type;
}

string Region::getType()
{
	return this->type;
}

void Region::setSymbol(string symbol)
{
	this->symbol = symbol;
}

string Region::getSymbol()
{
	return this->symbol;
}

void Region::setBorderRegion(bool borderRegion)
{
	this->borderRegion = borderRegion;
}

bool Region::getBorderRegion()
{
	return this->borderRegion;
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

vector<GamePiece*> Region::getGamePieces()
{
	return gamePieces;
}

void Region::setGamePiece(vector<GamePiece*> gamePieces)
{
	this->gamePieces = gamePieces;
}

void Region::addGamePiece(GamePiece* gamePiece)
{
	//pushing the address to the address container
	gamePieces.push_back(gamePiece);
}

void Region::removeGamePiece(GamePiece* gamePiece)
{
	for (int i = 0; i < gamePieces.size(); i++)
	{
		if (gamePieces[i]->getName() == gamePiece->getName())
		{
			gamePieces.erase(gamePieces.begin() + i);
		}
	}
}

vector<Region*> Region::getNeigborRegions()
{
	return neigborRegions;
}


void Region::printNeigbors() 
{
	std::cout << "--------------------------------------" << endl;
	std::cout << "My region id is " << this->id << "\t"; 
	std::cout << "border status " << this->borderRegion << "\t";
	std::cout << "My symbole is " << this->symbol << "\t";
	std::cout << "My land type is " << this->type << "      \t";
	std::cout << "My owner is " << this->owner_id << endl;
	cout << "My neigbor's ids are: " << endl;
	for (int i = 0; i < neigborRegions.size(); i++)
	{
		std::cout << neigborRegions[i]->getId() << ",";
	}
	std::cout << endl;
	std::cout << "--------------------------------------" << endl;
}


