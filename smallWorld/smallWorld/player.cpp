#include "stdafx.h"
#include "Player.h"

Player::Player()
{

}

void Player::picks_race()
{
	//todo
}

void Player::conquers()
{
	//todo
}

void Player::scores()
{
	//todo
}

void Player::addRegions(Region* region)
{
	//pushing the address to the address container
	regions->push_back(region);
}

void Player::removeRegions(Region* region)
{
	for (int i = 0; i < regions->size(); i++)
	{		
		if (regions->at(i)->getId() == region->getId())
		{
			regions->erase(regions->begin() + i);
		}
	}
}

vector<Region*>* Player::getRegions()
{
	return this->regions;
}

