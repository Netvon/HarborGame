#include "stdafx.h"
#include "Harbor.h"

Harbor::~Harbor()
{
}

const Vector<Product>& Harbor::GetProducts() const {
	return products;
}

const Cannon & Harbor::GetCannon(size_t index) const
{
	return cannons.get(index);
}

Cannon & Harbor::GetCannon(size_t index)
{
	return cannons.get(index);
}

size_t Harbor::GetCannonSize() const
{
	return cannons.size();
}

void Harbor::SellCannon(Cannon & cannon)
{
	IncreaseCannonStock(cannon.GetType(), 1);
}

void Harbor::IncreaseCannonStock(String & type, size_t byAmount)
{
	for (size_t i = 0; i < cannons.size(); i++)
	{
		auto& cannon = cannons.get(i);

		if (cannon.GetType() == type) {
			cannon.IncreaseAmmount(byAmount);
		}
	}
}

void Harbor::Randomize()
{
	RandomizeCannonAvailability();
}

void Harbor::RandomizeCannonAvailability()
{
	for (size_t i = 0; i < cannons.size(); i++)
	{
		auto& cannon = cannons.get(i);
		cannon.RandomizeAvailable();
	}
}

Vector<Distance> Harbor::getDistances() const {
	return distances;
}

const String& Harbor::GetName() const {
	return name;
}
