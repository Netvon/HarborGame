#include "stdafx.h"
#include "Cannon.h"
#include "RandomNumber.h"

Cannon::Cannon(const Cannon & other)
{
	price = other.price;
	type = other.type;
	minAmountAvailable = other.minAmountAvailable;
	maxAmountAvailable = other.maxAmountAvailable;
	available = 1;
}

Cannon::Cannon()
{
}

int Cannon::GetPrice() const {
	return price;
}

int Cannon::GetMinAmountAvailable() const {
	return minAmountAvailable;
}

int Cannon::GetMaxAmountAvailable() const {
	return maxAmountAvailable;
}

int Cannon::GetAvailable() const
{
	return available;
}

void Cannon::RandomizeAvailable()
{
	available = RandomNumber::Instance().Get(minAmountAvailable, maxAmountAvailable);
}

void Cannon::DecreaseAmmount(int amount)
{
	available -= amount;
}

void Cannon::IncreaseAmmount(int amount)
{
	available += amount;
}

String Cannon::GetType() const {
	return type;
}
