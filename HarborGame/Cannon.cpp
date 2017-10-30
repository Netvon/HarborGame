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

Cannon::Cannon(const String & pType, size_t amount)
{
	type = pType;
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

int Cannon::GenerateRandomDamage() const
{
	int min = 0;
	int max = 0;

	if (type.contains("zwaar"))
		max = 6;
	else if (type.contains("licht"))
		max = 2;
	else if (type.contains("middel"))
		max = 4;

	if (max == 0)
		return 0;

	return RandomNumber::Instance().Get<int>(min, max);;
}
