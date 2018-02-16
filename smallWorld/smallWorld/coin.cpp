#include "stdafx.h"
#include "Coin.h"

int Coin::getValue() {
	return this->value;
}
OneCoin::OneCoin()
{
	this->value = 1;

}
ThreeCoin::ThreeCoin()
{
	this->value = 3;

}
FiveCoin::FiveCoin()
{
	this->value = 5;

}
TenCoin::TenCoin()
{
	this->value = 10;

}