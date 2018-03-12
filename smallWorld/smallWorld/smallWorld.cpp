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
		std::cin >> map;
		
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
		std::cin >> nb_players;

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
		if (gameboard.getRegions()[i]->getType().compare("Mountain") == 0) // mountain Region
		{
			gameboard.getRegions()[i]->addGamePiece(gameDeck.getGamePiece("Mountain"));
		}
		else if (gameboard.getRegions()[i]->getOwner_id() == -2) // Lost tribe region
		{
			//gameboard.getRegions()[i].addGamePiece(gameDeck.getGamePiece("Mountain"));
		}
	}

	vector<Race*>* test;


	//first turn
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
		std::cin >> race;
		race--;
		players[i]->addRaces(test->at(race));
		test->erase(test->begin() + (race));

		for (int j = 0; j < (race); j++)
		{
			players[i]->removeCoin(1);
		}
		
		cout << "Player " << i << " has now " << players[i]->getRaces()->back()->getName() << " race with special power combo " << players[i]->getRaces()->back()->getPowerBadge()->getName() << endl;
		cout << "Player " << i << " has " << players[i]->getCoins()->size() << " coins with a total value of " << players[i]->scores() << endl;

	}

	// the main loop
	for (int i = 0; i < gameboard.getNb_of_turns(); i++)
	{
		for (int j = 0; j < players.size(); j++)
		{
			cout << "Player " << j << " turn " << i << endl;
		
			//check if player has an declined race so we know he has to pick a race
			//picks race and ends turn
			if (players[j]->getRaces()->back()->getIsDecline())
			{
				cout << "Player " << i << " pick a race and special power combo[1-6]:" << endl;

				test = gameDeck.getSixRandomRaces();
				for (int k = 0; k < test->size(); k++)
				{
					cout << k + 1 << " - " << test->at(k)->getName() << " with " << test->at(k)->getPowerBadge()->getName() << " combo " << endl;
				}
				int race;
				std::cin >> race;
				race--;
				players[i]->addRaces(test->at(race));
				test->erase(test->begin() + (race));

				for (int j = 0; j < (race); j++)
				{
					players[i]->removeCoin(1);
				}

				cout << "Player " << j << " has now " << players[j]->getRaces()->back()->getName() << " race with special power combo " << players[j]->getRaces()->back()->getPowerBadge()->getName() << endl;
				cout << "Player " << j << " has " << players[j]->getCoins()->size() << " coins with a total value of " << players[j]->scores() << endl;

			}
				
			
			cout << "Player " << j << " pick Regions to conquer!!! " << endl;
				int currentNbTokens = players[j]->getRaces()->back()->getNum_tokens();

				for (int k = 0; k < gameboard.getRegions().size(); k++)
				{
					//find all current player's regions
					if (gameboard.getRegions()[k]->getOwner_id() == j)
					{
						//add the rest of the tokens if more than 1 on a region
						if (gameboard.getRegions()[k]->getToken() > 1)
						{
							currentNbTokens += gameboard.getRegions()[k]->getToken() - 1;
							gameboard.getRegions()[k]->setToken(1);
						}
					}
				}

				//get the race token at the begining of the turn
				//int currentNbTokens = players[j]->getRaces()->back()->getNum_tokens();
				int raceValue = players[j]->getRaces()->back()->getValue();
				int powerBadgeValue = players[j]->getRaces()->back()->getPowerBadge()->getValue();

				//player's tokens at the begining of the turn
				players[j]->getRaces()->back()->setNum_tokens(currentNbTokens + raceValue + powerBadgeValue);

				//************************************
				//**************CONQUER***************
				//************************************
				while (true)
				{
					int playertokens = players[j]->getRaces()->back()->getNum_tokens();
					cout << "Player " << j << " has now " << playertokens << " race tokens from the values on each race and power badge " << raceValue << " and " << powerBadgeValue << endl;
					cout << "Must conquer border lands and andjacent lands " << endl;

					cout << "pick regions from 1 to " << gameboard.getRegions().size() << endl;
					cout << "0 to stop conquering" << endl;
					cout << "100 to go into decline" << endl;
					gameboard.printMapGraph();

					int region;
					std::cin >> region;

					// the following if proccesses the player's input
					if (region == 0)
					{
						cout << "stopped conquering" << endl;
						break;
					}
					//go to decline
					else if (region == 100)
					{
						cout << "Player " << j << " delined " << players[j]->getRaces()->back()->getName() << " race with special power combo " << players[j]->getRaces()->back()->getPowerBadge()->getName() << endl;
						players[j]->getRaces()->back()->setIsDecline(true);

						for (int ii = 0; ii < gameboard.getRegions().size(); ii++)
						{
							if (gameboard.getRegionsPtr()->at(ii)->getOwner_id() == j)
							{
								gameboard.getRegionsPtr()->at(ii)->setOwner_id(j+10); // owner id of the rigion (player number + 10) +10 mean it's in decline 
							}
						}					
						break;
					}

					else
					{
						if (gameboard.getRegions()[region - 1]->getOwner_id() == j)
						{
							cout << "can't conquer your own region" << endl;
							continue;
						}

						bool adjacent = false;
						for (int ii = 0; ii < gameboard.getRegions()[region - 1]->getNeigborRegions().size(); ii++)
						{
							if (gameboard.getRegions()[region - 1]->getNeigborRegions()[ii]->getOwner_id() == j)
							{
								adjacent = true;
								break;
							}

						}

						


						if (gameboard.getRegions()[region - 1]->getBorderRegion() || adjacent)
						{

						}
						else
						{
							cout << "can't conquer!! either not adjacent or not border region" << endl;
							continue;
						}

						int tokensOnRegion = gameboard.getRegions()[region - 1]->getToken();

						if (playertokens >= tokensOnRegion + 2) //normal conquer
						{
							cout << "able to conquer" << endl;
							gameboard.getRegions()[region - 1]->setToken(tokensOnRegion + 2);
							players[j]->getRaces()->back()->setNum_tokens(playertokens - (tokensOnRegion + 2));

							//-1 from total looser player's max tokens
							if (gameboard.getRegions()[region - 1]->getOwner_id() >= 0 && gameboard.getRegions()[region - 1]->getOwner_id() <= 8)
							{
								players[gameboard.getRegions()[region - 1]->getOwner_id()]->getRaces()->back()->setMax_num_tokens(players[gameboard.getRegions()[region - 1]->getOwner_id()]->getRaces()->back()->getMax_num_tokens() - 1);
							}

							gameboard.getRegionsPtr()->at(region - 1)->setOwner_id(j);
							//put tokens on it
							cout << " Region conquered " << endl;
						}

						else if (playertokens <= tokensOnRegion + 2 && playertokens > 0) //conquer using a die
						{
							cout << "able to conquer with reinforcement die" << endl;
							int dieValue = players[j]->rollDice();
							cout << "die value is " << dieValue << endl;
							if (playertokens + dieValue > tokensOnRegion)
							{
								//-1 from total looser player's max tokens
								if (gameboard.getRegions()[region - 1]->getOwner_id() >= 0 && gameboard.getRegions()[region - 1]->getOwner_id() <= 8)
								{
									players[gameboard.getRegions()[region - 1]->getOwner_id()]->getRaces()->back()->setMax_num_tokens(players[gameboard.getRegions()[region - 1]->getOwner_id()]->getRaces()->back()->getMax_num_tokens() - 1);
								}

								gameboard.getRegionsPtr()->at(region - 1)->setOwner_id(j);
								//put tokens on it
								cout << " Region conquered " << endl;
							}
							else
							{
								players[j]->getRaces()->back()->setMax_num_tokens(players[j]->getRaces()->back()->getMax_num_tokens() - 1);
								players[j]->getRaces()->back()->setNum_tokens(players[j]->getRaces()->back()->getNum_tokens() - 1);
								cout << " bad luck the number from die is not high enough " << endl;
							}

							cout << "end of conquest" << endl;
							break;
						}

						else //unable to conquer
						{
							cout << "unable to conquer" << endl;
						}

					}// for concuring region 
				}//allow player to keep conquering

				 //************************************
				 //**************SCORE*****************
				 //************************************
				int score = 0;

				for (int k = 0; k < gameboard.getRegions().size(); k++)
				{
					//find all current player's regions
					if (gameboard.getRegions()[k]->getOwner_id() == j)
					{
						//calculate score for each region  or declined region belonging to player
						if (gameboard.getRegions()[k]->getOwner_id() == j || gameboard.getRegions()[k]->getOwner_id() == j + 10)
						{
							score++;
						}
					}
				}

				while (score > 0)
				{
					if (score >= 10)
					{
						players[j]->addCoin(gameDeck.getTenCoin());
						score -= 10;
					}
					else if (score >= 5 && score < 10)
					{
						players[j]->addCoin(gameDeck.getFiveCoin());
						score -= 5;
					}
					else if (score >= 3 && score < 5)
					{
						players[j]->addCoin(gameDeck.getThreeCoin());
						score -= 3;
					}
					else 
					{
						players[j]->addCoin(gameDeck.getOneCoin());
						score--;
					}
				}
				cout << "Player " << j << " has now " << players[j]->getCoins()->size() << " coins with a total value of " << players[j]->scores() << endl;


		}

	}

	cout << "the game has ended!!! " << endl;
	cout << "the player with the highest coin values wins!!" << endl;

	for (int i = 0; i < players.size(); i++)
	{
		cout << "Player " << i << " has " << players[i]->getCoins()->size() << " coins with a total value of " << players[i]->scores() << endl;
	}

	for (int i = 0; i < players.size(); i++)
	{
		delete players[i];
		players[i] = NULL;
	}

	int x;
	std::cin >> x;
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