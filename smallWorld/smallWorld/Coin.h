#pragma once
#include "Region.h"
#include <vector>
using namespace std;

class Coin {
protected:

	int value;

public:
	
	//Coin();

	int getValue();

};

class OneCoin : public Coin
{

public:
	OneCoin();

};

class ThreeCoin : public Coin
{
 
public:
	ThreeCoin();

};

class FiveCoin : public Coin
{

public:
	FiveCoin();

};

class TenCoin : public Coin
{

public:
	TenCoin();

};



