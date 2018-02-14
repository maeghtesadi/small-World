#pragma once
#include <string>

using namespace std;

class GamePiece {
private:
	string name;

	//the player who controls this region
	int owner_id;


public:

	int getOwner_id();

	void setOwnerId();

	string getName();

	virtual void applySpecialPower() = 0;
};



class TrollLair : public GamePiece
{

public:
	TrollLair();

	void applySpecialPower();
};



class Fortress : public GamePiece
{

public:
	Fortress();

	void applySpecialPower();
};



class Mountain : public GamePiece
{

public:
	Mountain();

	void applySpecialPower();
};



class Encampment : public GamePiece
{

public:
	Encampment();

	void applySpecialPower();
};



class Hole_in_the_Ground : public GamePiece
{

public:
	Hole_in_the_Ground();

	void applySpecialPower();
};



class Hero : public GamePiece
{

public:
	Hero();

	void applySpecialPower();
};



class Dragon : public GamePiece
{

public:
	Dragon();

	void applySpecialPower();
};
