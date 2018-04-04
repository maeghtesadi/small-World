#pragma once
#include "Observer.h"
#include "Map.h"
class GameStatistics : public Observer {
public:
	GameStatistics();
	GameStatistics(Map* s);
	~GameStatistics();
	void subscribe(Map* s);
	void Update();
	void display();
private:
	Map * _subject;
};