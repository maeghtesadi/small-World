#include "stdafx.h"
#include "Race.h"

void Race::setIsActive(bool active) {
	this->isActive = active;
}

bool Race::getIsActive() {
	return this->isActive;
}

void Race::setIsDecline(bool decline) {
	this->isDecline = decline;
}

bool Race::getIsDecline(){
	return this->isDecline;
}

void Race::setOwnerId(int id ) {
	this->owner_id= id;
}

int Race::getOwner_id() {
	return this->owner_id;
}

void Race::setNum_tokens(int num_tokens) {
	this->num_tokens = num_tokens;
}

int Race::getNum_tokens() {
	return this->num_tokens;
}

void Race::setMax_num_tokens(int max_num_tokens) {
	this->max_num_tokens = max_num_tokens;
}

int Race::getMax_num_tokens() {
	return this->max_num_tokens;
}

int Race::getValue() {
	return this->value;
}

string Race::getName() {
	return this->name;
}

PowerBadge* Race::getPowerBadge() {
	return this->powerbadge;
}

void Race::setPowerBadge(PowerBadge* PB) {
	this->powerbadge = PB;
}




Amazons::Amazons()
{
	this->name="Amazons";
	this->isActive= false;
	this->isDecline=false;
	this->owner_id = -1;
	this->value=6;
	this->num_tokens = 0;
	this->max_num_tokens = 15;

}
Dwarves::Dwarves()
{
	this->name = "Dwarves";
	this->isActive = false;
	this->isDecline = false;
	this->owner_id = -1;
	this->value = 3;
	this->num_tokens = 0;
	this->max_num_tokens = 8;
}
Elves::Elves()
{
	this->name = "Elves";
	this->isActive = false;
	this->isDecline = false;
	this->owner_id = -1;
	this->value = 6;
	this->num_tokens = 0;
	this->max_num_tokens = 11;
}
Ghouls::Ghouls()
{
	this->name = "Ghouls";
	this->isActive = false;
	this->isDecline = false;
	this->owner_id = -1;
	this->value =5 ;
	this->num_tokens = 0;
	this->max_num_tokens = 10;
}
Ratmen::Ratmen()
{
	this->name = "Ratmen";
	this->isActive = false;
	this->isDecline = false;
	this->owner_id = -1;
	this->value = 8;
	this->num_tokens = 0;
	this->max_num_tokens = 13;
}
Skeletons::Skeletons()
{
	this->name = "Skeletons";
	this->isActive = false;
	this->isDecline = false;
	this->owner_id = -1;
	this->value = 6;
	this->num_tokens = 0;
	this->max_num_tokens = 20;
}
Sorcerers::Sorcerers()
{
	this->name = "Sorcerers";
	this->isActive = false;
	this->isDecline = false;
	this->owner_id = -1;
	this->value = 5;
	this->num_tokens = 0;
	this->max_num_tokens = 18;
}
Tritons::Tritons()
{
	this->name = "Tritons";
	this->isActive = false;
	this->isDecline = false;
	this->owner_id = -1;
	this->value = 6;
	this->num_tokens = 0;
	this->max_num_tokens = 11;
}
Giants::Giants()
{
	this->name = "Giants";
	this->isActive = false;
	this->isDecline = false;
	this->owner_id = -1;
	this->value = 6;
	this->num_tokens = 0;
	this->max_num_tokens = 11;
}
Halflings::Halflings()
{
	this->name = "Halflings";
	this->isActive = false;
	this->isDecline = false;
	this->owner_id = -1;
	this->value = 6;
	this->num_tokens = 0;
	this->max_num_tokens = 11;
}
Humans::Humans()
{
	this->name = "Humans";
	this->isActive = false;
	this->isDecline = false;
	this->owner_id = -1;
	this->value = 5;
	this->num_tokens = 0;
	this->max_num_tokens = 10;

}
Orcs::Orcs()
{
	this->name = "Orcs";
	this->isActive = false;
	this->isDecline = false;
	this->owner_id = -1;
	this->value = 5;
	this->num_tokens = 0;
	this->max_num_tokens = 10;
}
Trolls::Trolls()
{
	this->name = "Trolls";
	this->isActive = false;
	this->isDecline = false;
	this->owner_id = -1;
	this->value = 5;
	this->num_tokens = 0;
	this->max_num_tokens = 10;
}
Wizards::Wizards()
{
	this->name = "Wizards";
	this->isActive = false;
	this->isDecline = false;
	this->owner_id = -1;
	this->value = 5;
	this->num_tokens = 0;
	this->max_num_tokens = 10;
}
LostTribes::LostTribes()
{
	this->name = "LostTribes";
	this->isActive = false;
	this->isDecline = false;
	this->owner_id = -1;
	this->value = 0;
	this->num_tokens = 0;
	this->max_num_tokens = 18;
}