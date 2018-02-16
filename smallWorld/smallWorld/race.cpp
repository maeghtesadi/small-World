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

int Race::getValue() {
	return this->value;
}
string Race::getName() {
	return this->name;
}




Amazons::Amazons()
{
	this->name="Amazons";
	this->isActive= false;
	this->isDecline=false;
	this->owner_id = -1;
	this->value=6;

}
Dwarves::Dwarves()
{
	this->name = "Dwarves";
	this->isActive = false;
	this->isDecline = false;
	this->owner_id = -1;
	this->value = 3;

}
Elves::Elves()
{
	this->name = "Elves";
	this->isActive = false;
	this->isDecline = false;
	this->owner_id = -1;
	this->value = 6;

}
Ghouls::Ghouls()
{
	this->name = "Ghouls";
	this->isActive = false;
	this->isDecline = false;
	this->owner_id = -1;
	this->value =5 ;

}
Ratmen::Ratmen()
{
	this->name = "Ratmen";
	this->isActive = false;
	this->isDecline = false;
	this->owner_id = -1;
	this->value = 8;

}
Skeletons::Skeletons()
{
	this->name = "Skeletons";
	this->isActive = false;
	this->isDecline = false;
	this->owner_id = -1;
	this->value = 6;

}
Sorcerers::Sorcerers()
{
	this->name = "Sorcerers";
	this->isActive = false;
	this->isDecline = false;
	this->owner_id = -1;
	this->value = 5;

}
Tritons::Tritons()
{
	this->name = "Tritons";
	this->isActive = false;
	this->isDecline = false;
	this->owner_id = -1;
	this->value = 6;

}
Giants::Giants()
{
	this->name = "Giants";
	this->isActive = false;
	this->isDecline = false;
	this->owner_id = -1;
	this->value = 6;

}
Halflings::Halflings()
{
	this->name = "Halflings";
	this->isActive = false;
	this->isDecline = false;
	this->owner_id = -1;
	this->value = 6;

}
Humans::Humans()
{
	this->name = "Humans";
	this->isActive = false;
	this->isDecline = false;
	this->owner_id = -1;
	this->value = 5;

}
Orcs::Orcs()
{
	this->name = "Orcs";
	this->isActive = false;
	this->isDecline = false;
	this->owner_id = -1;
	this->value = 5;

}
Trolls::Trolls()
{
	this->name = "Trolls";
	this->isActive = false;
	this->isDecline = false;
	this->owner_id = -1;
	this->value = 5;

}
Wizards::Wizards()
{
	this->name = "Wizards";
	this->isActive = false;
	this->isDecline = false;
	this->owner_id = -1;
	this->value = 5;

}
LostTribes::LostTribes()
{
	this->name = "LostTribes";
	this->isActive = false;
	this->isDecline = false;
	this->owner_id = -1;
	this->value = 0;

}