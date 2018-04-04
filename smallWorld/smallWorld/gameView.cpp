#include "stdafx.h"
#include "GameView.h"
#include "Player.h"
#include <iostream>
using namespace std;

GameView::GameView() {
};
GameView::GameView(Player* s) {
	//Upon instantiation, attaches itself
	_subject = s;
	_subject->Attach(this);
};
GameView::~GameView() {
	//Upon destruction, detaches itself
	_subject->Detach(this);
};
void GameView::subscribe(Player* s) {
	//Called by Notify() when state of Subject changes
	_subject = s;
	_subject->Attach(this);
};
void GameView::Update() {
	//Called by Notify() when state of Subject changes
	display();
};
void GameView::display() {
	cout <<"OBSERVER PATTERN: " << _subject->getSummarySheet() << endl;
};