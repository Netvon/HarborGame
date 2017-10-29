#include "stdafx.h"
#include "Cannon.h"
#include "RandomNumber.h"

Cannon::Cannon(const Cannon & other, size_t amount)
{
	price = other.price;
	type = other.type;
	minAmountAvailable = other.minAmountAvailable;
	maxAmountAvailable = other.maxAmountAvailable;
	available = static_cast<int>(amount);
}

Cannon::Cannon() { }

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

bool Cannon::IsHeavy() const
{
	return type.contains("zwaar");
}

void Cannon::RandomizeAvailable()
{
	available = RandomNumber::Instance().Get(minAmountAvailable, maxAmountAvailable);
}

void Cannon::DecreaseAmount(int amount)
{
	available -= amount;

	if (available < 0) available = 0;
}

void Cannon::IncreaseAmount(int amount)
{
	available += amount;
}

String Cannon::GetType() const {
	return type;
}
