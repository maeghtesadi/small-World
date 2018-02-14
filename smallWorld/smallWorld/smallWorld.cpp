// smallWorld.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MapLoader.h"
#include "Player.h"
#include "DiceRollingFacility.h"
#include "Coin.h"
#include "Race.h"
#include "PowerBadge.h"

#include <iostream>
#include <vector>


using namespace std;

int main()
{
	
	//MapLoader mapLoader("map/small.map");
	//
	//Map map1;
	//string file1;
	//string pictureLocation1;
	//vector<vector<int>> edges1;
	//
	//
	//edges1 =mapLoader.getEdges();
	//file1 =mapLoader.getFile();
	//map1 = mapLoader.getMap();
	//pictureLocation1 = mapLoader.getPictureLocation();

	//map1.printMapGraph();

	//DiceRollingFacility d;
	//d.testDice();


	//setting up the deck
	vector<Race*> Races;
	{
		Amazons A;
		Dwarves B;
		Elves C;
		Ghouls D;
		Ratmen E;
		Skeletons F;
		Sorcerers G;
		Tritons H;
		Giants I;
		Halflings J;
		Humans K;
		Orcs L;
		Trolls M;
		Wizards N;
		LostTribes O;
		Races.push_back(&A);
		Races.push_back(&B);
		Races.push_back(&C);
		Races.push_back(&D);
		Races.push_back(&E);
		Races.push_back(&F);
		Races.push_back(&G);
		Races.push_back(&H);
		Races.push_back(&I);
		Races.push_back(&J);
		Races.push_back(&K);
		Races.push_back(&L);
		Races.push_back(&M);
		Races.push_back(&N);
		Races.push_back(&O);
	}
	
	vector<PowerBadge*> powers;
	{
		Alchemist A;
		Berserk B;
		Bivouacking C;
		Commando D;
		Diplomat E;
		DragonMaster F;
		Flying G;
		Forest H;
		Fortified I;
		Heroic J;
		Hill K;
		Merchant L;
		Mounted M;
		Pillaging N;
		Seafaring O;
		Spirit P;
		Stout Q;
		Swamp R;
		Underworld S;
		Wealthy T;

		powers.push_back(&A);
		powers.push_back(&B);
		powers.push_back(&C);
		powers.push_back(&D);
		powers.push_back(&E);
		powers.push_back(&F);
		powers.push_back(&G);
		powers.push_back(&H);
		powers.push_back(&I);
		powers.push_back(&J);
		powers.push_back(&K);
		powers.push_back(&L);
		powers.push_back(&M);
		powers.push_back(&N);
		powers.push_back(&O);
		powers.push_back(&P);
		powers.push_back(&Q);
		powers.push_back(&R);
		powers.push_back(&S);
		powers.push_back(&T);
	}

	vector<OneCoin*> oneCoins;
	for (int i=0; i < 35; i++) {
		OneCoin* temp = new OneCoin();
		oneCoins.push_back(temp);
	}

	vector<ThreeCoin*> threeCoins;
	for (int i = 0; i < 20; i++) {
		ThreeCoin* temp = new ThreeCoin();
		threeCoins.push_back(temp);
	}
	
	vector<FiveCoin*> fiveCoin;
	for (int i = 0; i < 24; i++) {
		FiveCoin* temp = new FiveCoin();
		fiveCoin.push_back(temp);
	}
	
	vector<TenCoin*> tenCoin;
	for (int i = 0; i < 30; i++) {
		TenCoin* temp = new TenCoin();
		tenCoin.push_back(temp);
	}

	
	
	
	
	
	
	
	
	
	
	
	for (int i = 0; i < oneCoins.size(); i++)
	{
		delete oneCoins[i];
	}

	for (int i = 0; i < threeCoins.size(); i++)
	{
		delete threeCoins[i];
	}

	for (int i = 0; i < fiveCoin.size(); i++)
	{
		delete fiveCoin[i];
	}

	for (int i = 0; i < tenCoin.size(); i++)
	{
		delete tenCoin[i];
	}

	int x;
	cin >> x;
    return 0;
}

