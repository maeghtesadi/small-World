#pragma once
#include <string>

using namespace std;

class PowerBadge {
private:
	
	string name;

	int value;

	//the player who controls this powerBagde
	int owner_id;


public:
	int getValue();

	int getOwner_id();

	void setOwnerId();

	string getName();

	//virtual void applySpecialPower() = 0;
};



class Alchemist : public PowerBadge
{

public:
	//Alchemist();

	void applySpecialPower();
};



class Berserk : public PowerBadge
{

public:
	//Berserk();

	void applySpecialPower();
};



class Bivouacking : public PowerBadge
{

public:
	//Bivouacking();

	void applySpecialPower();
};



class Commando : public PowerBadge
{

public:
	//Commando();

	void applySpecialPower();
};



class Diplomat : public PowerBadge
{

public:
	//Diplomat();

	void applySpecialPower();
};



class DragonMaster : public PowerBadge
{

public:
	//DragonMaster();

	void applySpecialPower();
};



class Flying : public PowerBadge
{

public:
	//Flying();

	void applySpecialPower();
};



class Forest : public PowerBadge
{

public:
	//Forest();

	void applySpecialPower();
};



class Fortified : public PowerBadge
{

public:
	//Fortified();

	void applySpecialPower();
};



class Heroic : public PowerBadge
{

public:
	//Heroic();

	void applySpecialPower();
};



class Hill : public PowerBadge
{

public:
	//Hill();

	void applySpecialPower();
};



class Merchant : public PowerBadge
{

public:
	//Merchant();

	void applySpecialPower();
};



class Mounted : public PowerBadge
{

public:
	//Mounted();

	void applySpecialPower();
};



class Pillaging : public PowerBadge
{

public:
	//Pillaging();

	void applySpecialPower();
};



class Seafaring : public PowerBadge
{

public:
	//Seafaring();

	void applySpecialPower();
};



class Spirit : public PowerBadge
{

public:
	//Spirit();

	void applySpecialPower();
};



class Stout : public PowerBadge
{

public:
	//Stout();

	void applySpecialPower();
};



class Swamp : public PowerBadge
{

public:
	//Swamp();

	void applySpecialPower();
};



class Underworld : public PowerBadge
{

public:
	//Underworld();

	void applySpecialPower();
};



class Wealthy : public PowerBadge
{

public:
	//Wealthy();

	void applySpecialPower();
};
