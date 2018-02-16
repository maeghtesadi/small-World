#pragma once
#include <string>
#include "PowerBadge.h"

using namespace std;

// we will use race as an abstraction and use inheritence to make specific races
class Race
{
protected:
	//name of the Race
	string name;

	//power badge
	PowerBadge* powerbadge;

	bool isActive; 

	bool isDecline;

	//the player who controls this Race
	int owner_id;

	//number of tokens
	int max_num_tokens;
	int num_tokens;

	int value;

public:

	int getValue();

	//int getNum_tokens();

	//void setNum_tokens();

	bool getIsActive();
	
	void setIsActive(bool active);

	bool getIsDecline();

	void setIsDecline(bool decline);

	int getOwner_id();

	void setOwnerId(int id);
	
	//int getMax_num_tokens();

	string getName();

	PowerBadge* getPowerBadge();

	void setPowerBadge();

	//virtual void applySpecialPower() = 0;

};



class Amazons : public Race
{

public:
	Amazons();

	void applySpecialPower();
	

};



class Dwarves : public Race
{

public:
	Dwarves();

	void applySpecialPower();
};



class Elves : public Race
{

public:
	Elves();

	void applySpecialPower();
};



class Ghouls : public Race
{

public:
	Ghouls();

	void applySpecialPower();
};



class Ratmen : public Race
{

public:
	Ratmen();

	void applySpecialPower();
};



class Skeletons : public Race
{

public:
	Skeletons();

	void applySpecialPower();
};



class Sorcerers : public Race
{

public:
	Sorcerers();

	void applySpecialPower();
};



class Tritons : public Race
{

public:
	Tritons();

	void applySpecialPower();
};



class Giants : public Race
{

public:
	Giants();

	void applySpecialPower();
};



class Halflings : public Race
{

public:
	Halflings();

	void applySpecialPower();
};



class Humans : public Race
{

public:
	Humans();

	void applySpecialPower();
};



class Orcs : public Race
{

public:
	Orcs();

	void applySpecialPower();
};



class Trolls : public Race
{

public:
	Trolls();

	void applySpecialPower();
};



class Wizards : public Race
{

public:
	Wizards();

	void applySpecialPower();
};



class  LostTribes : public Race
{

public:
	LostTribes();

	void applySpecialPower();
};