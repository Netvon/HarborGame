#include "stdafx.h"
#include "Ship.h"

Ship::Ship()
{

}

Ship::Ship(Ship * other)
{
	if (other != nullptr) {
		name = other->name;
		price = other->price;
		cargospace = 0u;
		maxCargospace = other->maxCargospace;
		cannons = 0u;
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
	return cargospace;
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

bool Ship::GetTinyTrait() const {
	return hasTinyTrait;
}

bool Ship::GetInertTrait() const {
	return hasInertTrait;
}

bool Ship::GetLightTrait() const {
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

void Ship::AddCannon(const Cannon & newCannon)
{
	for (size_t i = 0; i < cannonList.size(); i++)
	{
		auto& cannon = cannonList.get(i);

		if (cannon.GetType() == newCannon.GetType()) {
			cannon.IncreaseAmmount(1);
			return;
		}
	}

	cannonList.push_back({ newCannon });
}

void Ship::RemoveCannon(Cannon & cannonToRemove)
{
	for (size_t i = 0; i < cannonList.size(); i++)
	{
		auto& cannon = cannonList.get(i);

		if (cannon.GetType() == cannonToRemove.GetType()) {
			cannon.DecreaseAmmount(1);

			if (cannon.GetAvailable() <= 0) {
				cannonList.pop_index(i);
			}

			return;
		}
	}
}

Cannon & Ship::GetCannon(size_t index)
{
	return cannonList.get(index);
}
