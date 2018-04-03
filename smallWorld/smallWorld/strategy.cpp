#include "stdafx.h"
#include "Strategy.h"
#include <vector>
#include <chrono>
#include <random>


// attack random regions on the map, as long it is possible to attack based on the rules

//stops his turn on reinforcement die because he keeps conquering
int AggressiveStrategy::execute(Map* gameBoard, int raceToken, int maxRaceToken, int playerId) {
	if (raceToken == 0)
	{
		return 100;
	}

	vector<int> availableRegions = findAvailableRegions(gameBoard, playerId);
	
	//check if there's a no owner zone
	for (int i = 0; i < availableRegions.size(); i++)
	{
		if (gameBoard->getRegions()[availableRegions[i]-1]->getOwner_id() == -1) // attack the none owned regions first
		{
			return availableRegions[i];
		}
		else if (gameBoard->getRegions()[availableRegions[i]-1]->getOwner_id() > 9) // attack the declined regions first
		{
			return availableRegions[i];
		}
	}
	
	return availableRegions[0];

}

//A defensive player constantly looking to dismantle the opponent(s) empire, that is wants a slow, well defended
//advance

//stops his turn when there's 3 or 4 tokens available
int DefensiveStrategy::execute(Map* gameBoard, int raceToken, int maxRaceToken, int playerId) {
	
	if (raceToken == 3  || raceToken == 4)
	{
		return 0;
	}

	if (raceToken < 3)
	{
		return 100;
	}

	vector<int> availableRegions = findAvailableRegions(gameBoard, playerId);

	//check if there's a no owner zone
	for (int i = 0; i < availableRegions.size(); i++)
	{
		if (gameBoard->getRegions()[availableRegions[i] - 1]->getOwner_id() == -1)
		{
			return availableRegions[i];
		}
		else if (gameBoard->getRegions()[availableRegions[i] - 1]->getOwner_id() > 9)
		{
			return availableRegions[i];
		}
	}

	return availableRegions[0];
}

//A moderate player who know when to place the race in decline, which likely ends its hold on the
//board, but paves the way for his / her control of another race to renew his / her conquests

//if max number of acheivable tokens is less than 6 he will decline
int ModerateStrategy::execute(Map* gameBoard, int raceToken, int maxRaceToken, int playerId) {
	if (raceToken == 3 || raceToken == 4)
	{
		return 0;
	}

	if (maxRaceToken < 6)
	{
		return 100;
	}

	vector<int> availableRegions = findAvailableRegions(gameBoard, playerId);

	//check if there's a no owner zone
	for (int i = 0; i < availableRegions.size(); i++)
	{
		if (gameBoard->getRegions()[availableRegions[i] - 1]->getOwner_id() == -1)
		{
			return availableRegions[i];
		}
		else if (gameBoard->getRegions()[availableRegions[i] - 1]->getOwner_id() > 9)
		{
			return availableRegions[i];
		}
	}

	return availableRegions[0];
}


RandomStrategy::RandomStrategy() {

	
}


//A random player whose strategy reinforces random region conquers and random placing of race in
//decline
int RandomStrategy::execute(Map* gameBoard, int raceToken, int maxRaceToken, int playerId) {
	
	vector<int> availableRegions = findAvailableRegions(gameBoard, playerId);
	int randomRegionToConquer = rand() % (availableRegions.size() + 2) + 1;
	if (randomRegionToConquer == availableRegions.size() + 1)
	{
		return 0;
	}
	else if (randomRegionToConquer == availableRegions.size() + 2)
	{
		return 100;
	}
	else
	{
		return availableRegions[randomRegionToConquer];
	}
	
}

vector<int> Strategy::findAvailableRegions(Map* gameBoard , int playerId) 
{
	vector<int> availableRegions;
	for (int i = 0; i < gameBoard->getRegions().size(); i++)
	{
		if (gameBoard->getRegions()[i]->getBorderRegion() && gameBoard->getRegions()[i]->getOwner_id() != playerId) // If it is border region
		{
			bool alearlyInTheList = false;
			for (int k = 0; k < availableRegions.size(); k++)
			{
				if (availableRegions[k] == i + 1)// if it's not already in the list
				{
					alearlyInTheList = true;
					break;
				}
			}
			if (!alearlyInTheList)
			{
				availableRegions.push_back(i + 1);
			}
		}

		if (gameBoard->getRegions()[i]->getOwner_id() == playerId) // if the player owns this region
		{
			for (int j = 0; j < gameBoard->getRegions()[i]->getNeigborRegions().size(); j++) // look at all the neighbor regions
			{
				bool alearlyInTheList = false;
				if (gameBoard->getRegions()[i]->getNeigborRegions()[j]->getOwner_id() != playerId) // if the player doesn't already own the neighbor regions
				{
					for (int k = 0; k < availableRegions.size(); k++)
					{
						if (availableRegions[k] == gameBoard->getRegions()[i]->getNeigborRegions()[j]->getId())// if it's not already in the list
						{
							alearlyInTheList = true;
							break;
						}
					}
					if (!alearlyInTheList)
					{
						availableRegions.push_back(gameBoard->getRegions()[i]->getNeigborRegions()[j]->getId());
					}
				}
			}
		}
	}

	return availableRegions;
}