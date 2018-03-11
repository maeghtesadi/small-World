#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	die = new DiceRollingFacility();
	coins = new vector<Coin*>();
	races = new vector<Race*>();
}

void Player::picks_race(Race* race)
{
	addRaces(race);
}

void Player::conquers()
{
	//todo
}

int Player::scores()
{
	int score = 0;
	for (int i = 0; i < coins->size(); i++)
	{
		score += coins->at(i)->getValue();
	}
	return score;
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

void Player::addCoin(Coin* coin)
{
	coins->push_back(coin);
}

void Player::removeCoin(int value_of_coin)
{
	for (int i = 0; i < coins->size(); i++)
	{
		if (coins->at(i)->getValue() == value_of_coin)
		{
			coins->erase(coins->begin() + i);
			break;
		}
	}
}

vector<Coin*>* Player::getCoins()
{
	return this->coins;
}

int Player::rollDice() {
	return die->rollDice();
}

string Player::getSummarySheet()
{
	return summarySheet;
}

void Player::setSummarySheet(string summary)
{
	this->summarySheet;
}

void Player::appendSummarySheet(string summary)
{
	this->summarySheet + "\n " + summary;
}

void Player::addRaces(Race* race)
{
	races->push_back(race);
}

//void Player::removeRaces(Race* region)
//{
//	for (int i = 0; i < coins->size(); i++)
//	{
//		if (coins->at(i)->getValue() == value_of_coin)
//		{
//			coins->erase(coins->begin() + i);
//		}
//	}
//}

vector<Race*>* Player::getRaces()
{
	return this->races;
}

Player::~Player()
{
	delete die;
}