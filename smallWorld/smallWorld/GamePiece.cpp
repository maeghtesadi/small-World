#include "stdafx.h"
#include "GamePiece.h"

void GamePiece::setOwner_Id(int id) 
{
	this->owner_id = id;
};

int GamePiece::getOwner_id()
{
	return this->owner_id;
};

string GamePiece::getName()
{
	return this->name;
};


TrollLair::TrollLair()
{
	this->name = "Troll Lair";
};

Fortress::Fortress()
{
	this->name = "Fortress";
};

Mountain::Mountain()
{
	this->name = "Mountain";
};

Encampment::Encampment()
{
	this->name = "Encampment";
};

Hole_in_the_Ground::Hole_in_the_Ground()
{
	this->name = "Hole_in_the_Ground";
};

Hero::Hero()
{
	this->name = "Hero";
};

Dragon::Dragon()
{
	this->name = "Dragon";
};