#pragma once
#include "Map.h"


class Strategy {
public:
	vector<int> findAvailableRegions(Map* gameBoard, int playerId);
	//strategy execution
	virtual int execute(Map* gameBoard, int raceToken, int maxRaceToken, int playerId) = 0;
};


class AggressiveStrategy : public Strategy {
public:
	// attack random regions on the map, as long it is possible to attack based on the rules
	int execute(Map* gameBoard, int raceToken, int maxRaceToken, int playerId);
};


class DefensiveStrategy : public Strategy {
public:
	//A defensive player constantly looking to dismantle the opponent(s) empire, that is wants a slow, well defended
	//advance
	int execute(Map* gameBoard, int raceToken, int maxRaceToken, int playerId);
};

class ModerateStrategy : public Strategy {
public:
	//A moderate player who know when to place the race in decline, which likely ends its hold on the
	//board, but paves the way for his / her control of another race to renew his / her conquests
	int execute(Map* gameBoard, int raceToken, int maxRaceToken, int playerId);
};class RandomStrategy : public Strategy {
public:

	RandomStrategy();
	//A random player whose strategy reinforces random region conquers and random placing of race in
	//decline
	int execute(Map* gameBoard, int raceToken, int maxRaceToken, int playerId);
};