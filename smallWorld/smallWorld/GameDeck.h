#pragma once
#include "GamePiece.h"
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

	vector<GamePiece*> gamePiece;
	
	vector<Race*>* sixRaces;

public:

	GameDeck();

	vector<Race*>* getSixRandomRaces();

	OneCoin* getOneCoin();

	ThreeCoin* getThreeCoin();

	FiveCoin* getFiveCoin();

	TenCoin* getTenCoin();

	GamePiece* getGamePiece(string type);

	~GameDeck();
};