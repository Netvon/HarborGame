#include "stdafx.h"
#include "Ship.h"
#include "GameException.h"
#include "Product.h"

Ship::Ship()
{

}

Ship::Ship(Ship * other)
{
	if (other != nullptr) {
		name = other->name;
		price = other->price;
		maxCargospace = other->maxCargospace;
		maxCannons = other->maxCannons;
		maxHealth = other->maxHealth;

		hasInertTrait = other->hasInertTrait;
		hasLightTrait = other->hasLightTrait;
		hasTinyTrait = other->hasTinyTrait;

		currentHealth = other->maxHealth;
	}
}

const String& Ship::GetName() const {
	return name;
}

size_t Ship::GetPrice() const {
	return price;
}

size_t Ship::GetMaxCargospace() const {
	return maxCargospace;
}

size_t Ship::GetUsedCargospace() const
{
	size_t result = 0;
	for (size_t i = 0; i < productList.size(); i++)
	{
		auto& product = productList.get(i);
		result += product.GetAvailable();
	}

	return result;
}

size_t Ship::GetMaxCannons() const {
	return maxCannons;
}

size_t Ship::GetCannonsAmount() const
{
	size_t result = 0;
	for (size_t i = 0; i < cannonList.size(); i++)
	{
		auto& cannon = cannonList.get(i);
		result += cannon.GetAvailable();
	}

	return result;
}

size_t Ship::GetCurrentHealth() const {
	return currentHealth;
}

size_t Ship::GetMaxHealth() const {
	return maxHealth;
}

bool Ship::HasTinyTrait() const {
	return hasTinyTrait;
}

bool Ship::HasInertTrait() const {
	return hasInertTrait;
}

bool Ship::HasLightTrait() const {
	return hasLightTrait;
}

bool Ship::GetIsAtFullHealth() const
{
	return maxHealth == currentHealth;
}

size_t Ship::GetUniqueCannonAmount() const
{
	return cannonList.size();
}

bool Ship::operator==(Ship * other)
{
	if (this == nullptr && other == nullptr)
		return true;

	if (other == nullptr)
		return false;

	if (this == nullptr)
		return false;

	return name.equals(other->name);
}

bool Ship::operator!=(Ship * other)
{
	return !(this == other);
}

void Ship::SubtractHealth(size_t amount)
{
	if (currentHealth != 0) {
		currentHealth -= amount;
	}

	if (currentHealth < 0)
		currentHealth = 0;
}

void Ship::AddHealth(size_t amount)
{
	if (currentHealth + amount <= maxHealth) {
		currentHealth += amount;
	}
}

void Ship::AddCannon(const Cannon & newCannon, size_t amount)
{
	if (GetCannonsAmount() + amount  > GetMaxCannons())
		throw GameException("Max cannons reached");

	if (HasTinyTrait() && newCannon.IsHeavy())
		throw GameException("This cannon doesn't fit on the ship");

	for (size_t i = 0; i < cannonList.size(); i++)
	{
		auto& cannon = cannonList.get(i);

		if (cannon.GetType() == newCannon.GetType()) {
			cannon.IncreaseAmount(to_int(amount));
			return;
		}
	}

	cannonList.push_back({ newCannon, amount });
}

void Ship::AddProduct(const Product & newProduct, size_t amount)
{
	if (GetUsedCargospace() + amount  > GetMaxCargospace())
		throw GameException("The cargo space is full");

	for (size_t i = 0; i < productList.size(); i++)
	{
		auto& product = productList.get(i);

		if (product.GetName() == newProduct.GetName()) {
			product.IncreaseAmount(to_int(amount));
			return;
		}
	}

	productList.push_back({ newProduct, amount });
}

void Ship::RemoveCannon(Cannon & cannonToRemove)
{
	for (size_t i = 0; i < cannonList.size(); i++)
	{
		auto& cannon = cannonList.get(i);

		if (cannon.GetType() == cannonToRemove.GetType()) {
			cannon.DecreaseAmount(1);

			if (cannon.GetAvailable() <= 0) {
				cannonList.pop_index(i);
			}

			return;
		}
	}
}

void Ship::RemoveProduct(Product & productToRemove, size_t amount)
{
	for (size_t i = 0; i < cannonList.size(); i++)
	{
		auto& product = productList.get(i);

		if (product.GetName() == productToRemove.GetName()) {
			product.DecreaseAmount(to_int(amount));

			if (product.GetAvailable() <= 0) {
				productList.pop_index(i);
			}

			return;
		}
	}
}

Cannon & Ship::GetCannon(size_t index)
{
	return cannonList.get(index);
}

Product & Ship::GetProduct(size_t index)
{
	return productList.get(index);
}
