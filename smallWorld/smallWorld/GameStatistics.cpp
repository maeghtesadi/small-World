#include "stdafx.h"
#include "GameStatistics.h"
#include "Map.h"
#include <iostream>
using namespace std;

GameStatistics::GameStatistics() {
};

GameStatistics::GameStatistics(Map* s) {
	//Upon instantiation, attaches itself
	_subject = s;
	_subject->Attach(this);
};

GameStatistics::~GameStatistics() {
	//Upon destruction, detaches itself
	_subject->Detach(this);
};

void GameStatistics::subscribe(Map* s) {
	//Called by Notify() when state of Subject changes
	_subject = s;
	_subject->Attach(this);
};

void GameStatistics::Update() {
	//Called by Notify() when state of Subject changes
	display();
};

void GameStatistics::display() {
	int player1=0, player2=0, player3=0, player4=0, player5=0,unexplored=0,lostTribe=0;
	string player1bar = "=", player2bar = "=", player3bar = "=", player4bar = "=", player5bar = "=", unexploredbar = "=", lostTribebar = "=";

	for (int i = 0; i < _subject->getRegions().size(); i++)
	{
		if (_subject->getRegions().at(i)->getOwner_id() == -2)
		{
			lostTribe++;
			lostTribebar += "=";
		}
		else if (_subject->getRegions().at(i)->getOwner_id() == -1)
		{
			unexplored++;
			unexploredbar += "=";
		}
		else if (_subject->getRegions().at(i)->getOwner_id() == 0 || _subject->getRegions().at(i)->getOwner_id() == 0 + 10)
		{
			player1++;
			player1bar+= "=";
		}
		else if (_subject->getRegions().at(i)->getOwner_id() == 1 || _subject->getRegions().at(i)->getOwner_id() == 1 + 10)
		{
			player2++;
			player2bar += "=";
		}
		else if (_subject->getRegions().at(i)->getOwner_id() == 2 || _subject->getRegions().at(i)->getOwner_id() == 2 + 10)
		{
			player3++;
			player3bar += "=";
		}
		else if (_subject->getRegions().at(i)->getOwner_id() == 3 || _subject->getRegions().at(i)->getOwner_id() == 3 + 10)
		{
			player4++;
			player4bar += "=";
		}
		else if (_subject->getRegions().at(i)->getOwner_id() == 4 || _subject->getRegions().at(i)->getOwner_id() == 4 + 10)
		{
			player5++;
			player5bar += "=";
		}
	}
	cout << "--------------------------------------------------------------------------------------------------" << endl;
	cout << "===============================% of regions conquered=============================================" << endl;
	cout << "unexplored |" << lostTribebar	<< (lostTribe * 100 / _subject->getRegions().size()) << "%" <<endl;
	cout << "lostTribe  |" << unexploredbar << (unexplored * 100 / _subject->getRegions().size()) << "%" << endl;
	cout << "player1    |" << player1bar	<< (player1 * 100 / _subject->getRegions().size()) << "%" << endl;
	cout << "player2    |" << player2bar	<< (player2 * 100 / _subject->getRegions().size()) << "%" << endl;
	cout << "player3    |" << player3bar	<< (player3 * 100 / _subject->getRegions().size()) << "%" << endl;
	cout << "player4    |" << player4bar	<< (player4 * 100 / _subject->getRegions().size()) << "%" << endl;
	cout << "player5    |" << player5bar	<< (player5 * 100 / _subject->getRegions().size()) << "%" << endl;
	cout << "==================================================================================================" << endl;
	cout << "--------------------------------------------------------------------------------------------------" << endl;
};