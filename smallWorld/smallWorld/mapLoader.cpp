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
	map = new Map(); // we use new because we want to modify Map at run time
	setMap(this->file);
	setMapGraph();
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

	bool line2;

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

			line2 = false;
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
			if (line2 == false)
			{
				this->pictureLocation = line;
				line2 = true;
			}
			else
			{
				stringstream ss(line);
				int turns;
				ss >> turns;
				map->setNb_of_turns(turns);
			}
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

			stringstream ss2(array[2]);
			int y_pos;
			ss2 >> y_pos;

			// On the stack
			Point point = Point::Point(x_pos, y_pos);

			// Region type and Lost Trible
			string type;
			int ownerID;
			if (array[3].find("LT") != std::string::npos) //has lost tribes
			{
				type = array[3].substr(0, array[3].size()-2);
				ownerID = -2;
			}
			else //doesn't have lost tribes
			{
				type = array[3];
				ownerID = -1;
			}

			// Region symbol and Lost Trible
			string symbol = array[4];
			
			// border Region?
			bool border;
			
			if (array[5].find("Yes") != std::string::npos) //border Region
			{
				border = true;
			}
			else //Not border Region
			{
				border = false;
			}
			
			
			
			/*
			  Make regions with the values obtained from the file.
			  Point is passed by value here, which is intentional.
			*/
			Region* loadedRegion = new Region(id, 5, type, ownerID, symbol, border, point);

			loadedMap.push_back(*loadedRegion);

			int count = 0;
			vector<int> neighbors;
			for (int i = 6; i < array.size(); i++)
			{
				stringstream ss3(array[i]);
				int value;
				ss3 >> value;
				neighbors.push_back(value);
				
			}
			edges.push_back(neighbors);
			
			delete loadedRegion;
			loadedRegion = NULL;
		}

	}

	//set our map member fuction with the values gotten from the file
	for (int i = 0; i < loadedMap.size(); i++)
	{
		Region temp = loadedMap[i];
		map->getRegionsPtr()->push_back(temp);
	}
}

void MapLoader::setMapGraph() {
	//for each regions, connect to other regions based on values from the file
	for (int i = 0; i < map->getRegions().size(); i++)
	{
		vector<Region*> temp;

		for (int j = 0; j < edges[i].size(); j++)
		{
			int temp2 = edges[i][j] - 1;
			Region* tempRegion = &map->getRegions().at(temp2); // &map->getRegions().at(temp2) putting a '&' at the begining turns everything into a pointer
			temp.push_back(tempRegion); //a neighbor region   // [edges[i][j] - 1] index of the neigbor region in map.getRegions()		
		}
		map->getRegionsPtr()->at(i).setNeigborRegions(temp);
		//map->getRegionsPtr()->at(i)->setNeigborRegions(&temp);
		//*(map.getRegionsPtr() + i)  ;
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
	return *map;
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

MapLoader::~MapLoader()
{
	delete this->map;
}