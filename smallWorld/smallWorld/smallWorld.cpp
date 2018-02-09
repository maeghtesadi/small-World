// smallWorld.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MapLoader.h"
#include <iostream>
#include <ctime>


using namespace std;

int main()
{
	//srand(time(0));
	//for (int i = 0; i<50; i++)
	//{
	//	cout << (rand() % 6) + 1 << endl;  //it will generate numbers between 0 - 5, we add  + 1 so that the numbers wouldn't be zero based
	//}
	
	MapLoader mapLoader("map/small.map");
	
	Map map1;
	string file1;
	string pictureLocation1;
	vector<vector<int>> edges1;
	
	
	edges1 =mapLoader.getEdges();
	file1 =mapLoader.getFile();
	map1 = mapLoader.getMap();
	pictureLocation1 = mapLoader.getPictureLocation();

	map1.printMapGraph();
	
	
	int x;
	cin >> x;
    return 0;
}

