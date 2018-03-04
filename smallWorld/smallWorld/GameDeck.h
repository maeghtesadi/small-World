#pragma once
#include "Coin.h"
#include "Race.h"
#include "PowerBadge.h"

using namespace std;

class GameDeck {

private:

	vector<PowerBadge*>* powers;

	vector<Race*>* races;

	vector<OneCoin*> oneCoins;

	vector<ThreeCoin*> threeCoins;

	vector<FiveCoin*> fiveCoin;

	vector<TenCoin*> tenCoin;
	
	vector<Race*>* sixRaces;

public:

	GameDeck();

	vector<Race*>* getSixRandomRaces();

	OneCoin* getOneCoin();

	ThreeCoin* getThreeCoin();

	FiveCoin* getFiveCoin();

	TenCoin* getTenCoin();

	~GameDeck();
};