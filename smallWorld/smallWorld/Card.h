#pragma once

class Card {
public:
	Card(Race* race, Power* power) : race(race), power(power);
	Race * race;
	Power * power;
};
