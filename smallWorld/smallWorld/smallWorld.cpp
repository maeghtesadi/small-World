// smallWorld.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MapLoader.h"
#include "Player.h"
#include "DiceRollingFacility.h"

#include <iostream>
#include <ctime>


using namespace std;

int main()
{
	
	//MapLoader mapLoader("map/small.map");
	//
	//Map map1;
	//string file1;
	//string pictureLocation1;
	//vector<vector<int>> edges1;
	//
	//
	//edges1 =mapLoader.getEdges();
	//file1 =mapLoader.getFile();
	//map1 = mapLoader.getMap();
	//pictureLocation1 = mapLoader.getPictureLocation();

	//map1.printMapGraph();

	DiceRollingFacility d;
	d.testDice();

	int x;
	cin >> x;
    return 0;
}

