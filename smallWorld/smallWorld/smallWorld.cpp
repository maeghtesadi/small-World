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
#include <Windows.h>
#include <filesystem>


using namespace std;

vector<string> list_files(string directory);
int main()
{
	
	//MapLoader mapLoader("map/small.map");

	//Map map1;
	//string file1;
	//string pictureLocation1;
	//vector<vector<int>> edges1;


	//edges1 = mapLoader.getEdges();
	//file1 = mapLoader.getFile();
	//map1 = mapLoader.getMap();
	//pictureLocation1 = mapLoader.getPictureLocation();

	//map1.printMapGraph();

	//cout << "********************************************" << endl;
	//cout << "the graph is " << map1.isConnected() << endl;
	//cout << "********************************************" << endl;


	//MapLoader mapLoader2("map/smallInvalid.map");

	//Map map2;
	//string file2;
	//string pictureLocation2;
	//vector<vector<int>> edges2;


	//edges2 = mapLoader2.getEdges();
	//file2 = mapLoader2.getFile();
	//map2 = mapLoader2.getMap();
	//pictureLocation2 = mapLoader2.getPictureLocation();

	//map2.printMapGraph();

	//cout << "********************************************" << endl;
	//cout << "the graph is " << map2.isConnected() << endl;
	//cout << "********************************************" << endl;



	//DiceRollingFacility d;
	//d.testDice();


	////setting up the deck
	//
	//GameDeck gameDeck;
	//vector<Race*>* test = gameDeck.getSixRandomRaces();

	//Player p;
	//p.addCoin(gameDeck.getOneCoin());
	//p.addCoin(gameDeck.getOneCoin());
	//p.addCoin(gameDeck.getFiveCoin());
	//p.addRaces(test->at(0));

	//cout << endl << endl;
	//cout << "player has " << p.getCoins()->size() << " coins with a total value of " << p.scores() << endl;
	//cout << "player has " << p.getRaces()->at(0)->getName() << " race and " << p.getRaces()->at(0)->getPowerBadge()->getName() << endl;


	//assignment 2

	//WIN32_FIND_DATA data;
	//string directory = "map/*";
	//wstring direct(directory.begin(), directory.end());
	//HANDLE hFind = FindFirstFile(direct.c_str(),&data);      // DIRECTORY

	//if (hFind != INVALID_HANDLE_VALUE) {
	//	do {
	//		wstring name = data.cFileName;
	//		string test(name.begin(), name.end());
	//		std::cout << test << endl;
	//	} while (FindNextFile(hFind, &data));
	//	FindClose(hFind);
	//}

	cout << "choose a map to be loaded from the following maps:" << endl;

	vector<string> maps = list_files("map/*");
	int map;
	
	for (int i = 0; i < maps.size(); i++)
	{
		cout << i << "-" <<  maps[i] << endl;
	}

	MapLoader* mapLoader = NULL;
	
	//**************************************************************************
	//here debugger will cause a problem if we choose invalid maps back to back
	//mostly for big map
	//**************************************************************************
	while (true)
	{
		cin >> map;
		
		if (map > maps.size()-1)
		{
			break;
		}

		
		MapLoader* test = new MapLoader("map/" + maps[map]);
		

		if (test->getMap().isConnected())
		{
			mapLoader = test;
			break;
		}

		cout << "please choose annother map" << endl;
		delete test;
		test = NULL;
	}

	cout << "choose the number of players[2-5]:" << endl;
	vector<Player*> players;
	int nb_players;
	while (true)
	{
		cin >> nb_players;

		if (nb_players < 6 && nb_players > 1)
		{
			break;
		}

		cout << "please try again" << endl;

	}

	for (int i = 0; i < nb_players; i++)
	{
		players.push_back(new Player());
	}


	//setting up the deck
	
	GameDeck gameDeck;
	vector<Race*>* available_races = gameDeck.getSixRandomRaces();
	
	Map gameboard = mapLoader->getMap();
	
	for (int i = 0; i < gameboard.getRegions().size(); i++)
	{
		if (gameboard.getRegions()[i].getType().compare("Mountain") == 0) // mountain Region
		{
			gameboard.getRegions()[i].addGamePiece(gameDeck.getGamePiece("Mountain"));
		}
		else if (gameboard.getRegions()[i].getOwner_id() == -2) // Lost tribe region
		{
			//gameboard.getRegions()[i].addGamePiece(gameDeck.getGamePiece("Mountain"));
		}
	}

	vector<Race*>* test;


	
	for (int i = 0; i < players.size(); i++)
	{
		cout << "Player " << i << " turn " << endl;

		for (int l = 0; l < 5; l++)
		{
			players[i]->addCoin(gameDeck.getOneCoin());
		}

		cout << "Player " << i << " has " << players[i]->getCoins()->size() << " coins with a total value of " << players[i]->scores() << endl;

		cout << "Player " << i << " pick a race and special power combo[1-6]:" << endl;
		
		test = gameDeck.getSixRandomRaces();
		for (int k = 0; k < test->size(); k++)
		{
			cout << k + 1 << " - " << test->at(k)->getName() << " with " << test->at(k)->getPowerBadge()->getName() << " combo " << endl;
		}
		int race;
		cin >> race;
		race--;
		players[i]->addRaces(test->at(race));
		test->erase(test->begin() + (race));

		for (int j = 0; j < (race); j++)
		{
			players[i]->removeCoin(1);
		}
		
		cout << "Player " << i << " has now " << players[i]->getRaces()->front()->getName() << "race with special power combo " << players[i]->getRaces()->front()->getPowerBadge()->getName() << endl;
		cout << "Player " << i << " has " << players[i]->getCoins()->size() << " coins with a total value of " << players[i]->scores() << endl;

	}


	for (int i = 0; i < gameboard.getNb_of_turns(); i++)
	{
		for (int j = 0; j < players.size(); j++)
		{
			cout << "Player " << j << " turn " << i << endl;
			cout << "Player " << j << " pick Regions to conquer!!! " << endl;
			cout << "Must conquer border lands and andjacent lands " << endl;

			cout << "pick regions from 1 to " << gameboard.getRegions().size() << endl;
			gameboard.printMapGraph();

			int region;
			cin >> region;

			//players[i]->conquers()

		}

	}



	// The game will alwaysbe in one of four states
	//enum class State
	//{
	//	pick, LEVELING_UP, GAME_OVER, PLAYING
	//};
	//// Start with the GAME_OVER state
	//	State state = State::GAME_OVER;

	//the main game loop
	//while (true)
	//{
		//if (state == state::playing) {}
		//if (state == state::playing) {}
		//if (state == state::playing) {}
		//if (state == state::playing) {}

	//}










	int x;
	cin >> x;
	return 0;

}

vector<string> list_files(string directory)
{
	WIN32_FIND_DATA data;
	//string directory = "map/*";
	wstring direct(directory.begin(), directory.end());
	HANDLE hFind = FindFirstFile(direct.c_str(), &data);      // DIRECTORY

	vector<string> result;

	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			wstring name = data.cFileName;
			string test(name.begin(), name.end());
			if (test.at(0) == '.')
			{
				continue;
			}
			result.push_back(test);

		} while (FindNextFile(hFind, &data));
		FindClose(hFind);
	}

	return result;
}