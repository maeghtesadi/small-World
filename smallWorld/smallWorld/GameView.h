#pragma once
#include "Observer.h"
#include "Player.h"
class GameView : public Observer {
public:
	GameView();
	GameView(Player* s);
	~GameView();
	void subscribe(Player* s);
	void Update();
	void display();
private:
	Player * _subject;
};