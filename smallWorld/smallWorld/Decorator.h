#pragma once
#include <string>

using namespace std; 

class Display
{
public:
	virtual string message() = 0;

private:

};

class AddOnDecorator : public Display {
public:
	virtual string message() = 0;
};

// Display the percentage of regions owned/lost for each player,
// update the view when any player conquers / loses a region.
class DominationObserverDecorator: public AddOnDecorator {
public:
	virtual string message() = 0;
};

//Display the cards owned by every player, update the view when
//any player�s hand is changing.
class HandsObserverDecorator : public AddOnDecorator {
public:
	virtual string message() = 0;
};

//Display what player victory coins he/she scores, update the view
//when any more coins earned by a player.
class CoinsObserverDecorator : public AddOnDecorator {
public:
	virtual string message() = 0;
};
