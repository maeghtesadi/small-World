#include "stdafx.h"
#include "MapLoader.h"
#include <iostream>
#include <iterator>
#include <sstream>

using namespace std;

MapLoader::MapLoader()
{

}

MapLoader::MapLoader(string file) 
{
	this->file = file;
	setMap(this->file);
}

void MapLoader::setMap(string file)
{
	ifstream inputfile;

	inputfile.open(file, ios::in);

	//for reading the file
	char characters[50];
	string line;

	//to keep track of state
	bool picturePart;
	bool mapPart;

	//for making the map
	vector<Region> loadedMap;

	while (!inputfile.eof())
	{
		inputfile.getline(characters, 50);
		line = characters;

		if (line.find("Picture") != string::npos) 
		{
			//we found the picture file
			picturePart = true;
			mapPart = false;
			//go to the next loop iteration
			continue;
		}
		else if (line.find("Region") != string::npos)
		{
			//we found the region configuration part of the file
			picturePart = false;
			mapPart = true;
			//go to the next loop iteration
			continue;
		}



		if (picturePart)
		{
			this->pictureLocation = line;
		}
		else if (mapPart)
		{
			//the following lines of code will split each line of the file at every occurence of ',' and put the results into a vector variable called array
			vector<string> array;
			size_t pos = 0, found;
			while ((found = line.find_first_of(',', pos)) != string::npos) {
				array.push_back(line.substr(pos, found - pos));
				pos = found + 1;
			}
			array.push_back(line.substr(pos));

			//convert strings into int
			stringstream ss(array[0]);
			int id;
			ss >> id;

			stringstream ss1(array[1]);
			int x_pos;
			ss1 >> x_pos;

			stringstream ss2(array[1]);
			int y_pos;
			ss2 >> y_pos;

			//make regions with the values obtained from the file
			Region loadedRegion(id, x_pos, y_pos,5);

			loadedMap.push_back(loadedRegion);

			int count = 0;
			vector<int> neighbors;
			for (int i = 3; i < array.size(); i++)
			{
				stringstream ss3(array[i]);
				int value;
				ss3 >> value;
				neighbors.push_back(value);
				
			}
			edges.push_back(neighbors);
			
		}

	}

	//set our map member fuction with the values gotten from the file
	for (int i = 0; i < loadedMap.size(); i++)
	{
		Region temp = loadedMap[i];
		map.getRegionsPtr()->push_back(temp);
	}
}

void MapLoader::setMap()
{
	if (file.empty())
	{
		cout << "ERROR set a .map file into file loader" << endl;
	}
	else
	{
		setMap(file);
	}

}

Map MapLoader::getMap()
{
	return map;
}

string MapLoader::getFile()
{
	return file;
}

string MapLoader::getPictureLocation()
{
	return pictureLocation;
}

vector<vector<int>> MapLoader::getEdges()
{
	return edges;
}