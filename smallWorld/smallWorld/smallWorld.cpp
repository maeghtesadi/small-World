// smallWorld.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MapLoader.h"
#include "Player.h"
#include "DiceRollingFacility.h"
#include "Coin.h"
#include "Race.h"
#include "PowerBadge.h"
#include "GameDeck.h"

#include <iostream>
#include <vector>


using namespace std;

int main()
{
	
	MapLoader mapLoader("map/small.map");

	Map map1;
	string file1;
	string pictureLocation1;
	vector<vector<int>> edges1;


	edges1 = mapLoader.getEdges();
	file1 = mapLoader.getFile();
	map1 = mapLoader.getMap();
	pictureLocation1 = mapLoader.getPictureLocation();

	map1.printMapGraph();

	cout << "********************************************" << endl;
	cout << "the graph is " << map1.isConnected() << endl;
	cout << "********************************************" << endl;


	MapLoader mapLoader2("map/smallInvalid.map");

	Map map2;
	string file2;
	string pictureLocation2;
	vector<vector<int>> edges2;


	edges2 = mapLoader2.getEdges();
	file2 = mapLoader2.getFile();
	map2 = mapLoader2.getMap();
	pictureLocation2 = mapLoader2.getPictureLocation();

	map2.printMapGraph();

	cout << "********************************************" << endl;
	cout << "the graph is " << map2.isConnected() << endl;
	cout << "********************************************" << endl;



	DiceRollingFacility d;
	d.testDice();


	//setting up the deck
	
	GameDeck gameDeck;
	vector<Race*>* test = gameDeck.getSixRandomRaces();

	Player p;
	p.addCoin(gameDeck.getOneCoin());
	p.addCoin(gameDeck.getOneCoin());


	int x;
	cin >> x;
	return 0;

}

