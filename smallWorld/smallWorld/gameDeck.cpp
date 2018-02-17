#include "stdafx.h"
#include "GameDeck.h"
#include <chrono>
#include <random>

GameDeck::GameDeck() {
	srand(time(0)); 
	
	powers = new vector<PowerBadge*>();
	races = new vector<Race*>();
	sixRaces = new vector<Race*>();


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
		races->push_back(&A);
		races->push_back(&B);
		races->push_back(&C);
		races->push_back(&D);
		races->push_back(&E);
		races->push_back(&F);
		races->push_back(&G);
		races->push_back(&H);
		races->push_back(&I);
		races->push_back(&J);
		races->push_back(&K);
		races->push_back(&L);
		races->push_back(&M);
		races->push_back(&N);
		races->push_back(&O);
	}

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

		powers->push_back(&A);
		powers->push_back(&B);
		powers->push_back(&C);
		powers->push_back(&D);
		powers->push_back(&E);
		powers->push_back(&F);
		powers->push_back(&G);
		powers->push_back(&H);
		powers->push_back(&I);
		powers->push_back(&J);
		powers->push_back(&K);
		powers->push_back(&L);
		powers->push_back(&M);
		powers->push_back(&N);
		powers->push_back(&O);
		powers->push_back(&P);
		powers->push_back(&Q);
		powers->push_back(&R);
		powers->push_back(&S);
		powers->push_back(&T);

	}

	
	for (int i = 0; i < 35; i++) {
		OneCoin* temp = new OneCoin();
		oneCoins.push_back(temp);
	}

	for (int i = 0; i < 20; i++) {
		ThreeCoin* temp = new ThreeCoin();
		threeCoins.push_back(temp);
	}

	for (int i = 0; i < 24; i++) {
		FiveCoin* temp = new FiveCoin();
		fiveCoin.push_back(temp);
	}

	for (int i = 0; i < 30; i++) {
		TenCoin* temp = new TenCoin();
		tenCoin.push_back(temp);
	}

}

vector<Race*>* GameDeck::getSixRandomRaces()
{
	for (int i = sixRaces->size(); i < 6 ; i++)
	{
		if (races->size() == 0)
		{
			break;
		}
		int Random_race = (rand() % races->size());
		int Random_power = (rand() % powers->size());

		races->at(Random_race)->setPowerBadge(powers->at(Random_power));
		sixRaces->push_back(races->at(Random_race));
		races->erase(races->begin() + i);
		powers->erase(powers->begin() + i);
	}

	return sixRaces;



}

OneCoin* GameDeck::getOneCoin()
{
	oneCoins.pop_back();
	return oneCoins.at(0);
}

ThreeCoin* GameDeck::getThreeCoin()
{
	threeCoins.pop_back();
	return threeCoins.at(0);
}

FiveCoin* GameDeck::getFiveCoin()
{
	fiveCoin.pop_back();
	return fiveCoin.at(0);
}

TenCoin* GameDeck::getTenCoin()
{
	tenCoin.pop_back();
	return tenCoin.at(0);
}


GameDeck::~GameDeck()
{
	
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

	for (int i = 0; i < races->size(); i++)
	{
		delete races->at(i);
	}

	for (int i = 0; i < powers->size(); i++)
	{
		delete powers->at(i);
	}

	for (int i = 0; i < sixRaces->size(); i++)
	{
		delete sixRaces->at(i);
	}
}
