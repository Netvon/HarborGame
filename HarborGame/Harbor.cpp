#include "stdafx.h"
#include "Harbor.h"
#include "GameException.h"
#include "Player.h"


const Product & Harbor::GetProduct(size_t index) const
{
	return products.get(index);
}

const Product & Harbor::GetProduct(const String & name) const
{
	for (size_t i = 0; i < products.size(); i++)
	{
		auto& product = products.get(i);

		if (product.GetName() == name) {
			return product;
		}
	}
}

Product & Harbor::GetProduct(size_t index)
{
	return products.get(index);
}

size_t Harbor::GetProductsSize() const
{
	return products.size();
}

bool Harbor::GetProductIsInStock(size_t index) const
{
	return products.get(index).GetAvailable() > 0;
}

void Harbor::BuyProduct(Player & forPlayer, Product & product, size_t amount)
{
	if (product.GetAvailable() <= 0)
		throw GameException("This product is out of stock");

	forPlayer.AddProductToShip(product, amount);
	DecreaseProductStock(product.GetName(), amount);
}

void Harbor::SellProduct(Player & forPlayer, Product & product, size_t amount, size_t price)
{
	forPlayer.AddGold(amount * price);
	auto& ship = forPlayer.GetShip();

	IncreaseProductStock(product.GetName(), amount);

	ship.RemoveProduct(product, amount);

	
}

void Harbor::IncreaseProductStock(const String & name, size_t byAmount)
{
	for (size_t i = 0; i < products.size(); i++)
	{
		auto& product = products.get(i);

		if (product.GetName().equals(name)) {
			product.IncreaseAmount(to_int(byAmount));
		}
	}
}

void Harbor::DecreaseProductStock(const String & name, size_t byAmount)
{
	for (size_t i = 0; i < products.size(); i++)
	{
		auto& product = products.get(i);

		if (product.GetName() == name) {
			product.DecreaseAmount(to_int(byAmount));
		}
	}
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


bool Harbor::GetCannonIsInStock(size_t index) const
{
	return cannons.get(index).GetAvailable() > 0;
}

void Harbor::BuyCannon(Player & forPlayer, Cannon & cannon, size_t amount)
{
	if (cannon.GetAvailable() <= 0)
		throw GameException("This cannon is out of stock");

	forPlayer.AddCannonToShip(cannon, amount);
	cannon.DecreaseAmount(amount);
}

void Harbor::SellCannon(Cannon & cannon)
{
	IncreaseCannonStock(cannon.GetType(), 1);
}

void Harbor::IncreaseCannonStock(const String & type, size_t byAmount)
{
	for (size_t i = 0; i < cannons.size(); i++)
	{
		auto& cannon = cannons.get(i);

		if (cannon.GetType() == type) {
			cannon.IncreaseAmount(to_int(byAmount));
		}
	}
}

void Harbor::DecreaseCannonStock(const String & type, size_t byAmount)
{
	for (size_t i = 0; i < cannons.size(); i++)
	{
		auto& cannon = cannons.get(i);

		if (cannon.GetType() == type) {
			cannon.DecreaseAmount(to_int(byAmount));
		}
	}
}

void Harbor::Randomize()
{
	RandomizeCannonAvailability();
	RandomizeProductAvailability();
}

void Harbor::RandomizeProductAvailability()
{
	for (size_t i = 0; i < products.size(); i++)
	{
		auto& product = products.get(i);
		product.Randomize();
	}
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
