#pragma once
#include <iostream>

using namespace std;

class Decorator
{
public:
	virtual void center()
	{
		cout << "Hi, this is where you write stuff. you will add on to this, it is your inner shell\n";		
	}
};

class LayerOne : public Decorator
{
public:
	virtual void center()
	{
		Decorator::center();
		cout << "Hi, this is where you write MORE stuff. you will add on to this, it is your wrapped shell\n";
		// This is where you would add additional functionality to center (after calling base).
	}
};

