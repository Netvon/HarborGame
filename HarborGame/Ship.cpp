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
		cargospace = other->cargospace;
		cannons = other->cannons;
		maxHealth = other->maxHealth;

		hasInertTrait = other->hasInertTrait;
		hasLightTrait = other->hasLightTrait;
		hasTinyTrait = other->hasTinyTrait;

		currentHealth = other->maxHealth;
	}
}

Ship::~Ship()
{

}

void Ship::setCurrentHealth(int pCurrentHealth) {
	currentHealth = pCurrentHealth;
}

const String& Ship::GetName() const {
	return name;
}

int Ship::GetPrice() const {
	return price;
}

int Ship::GetMaxCargospace() const {
	return cargospace;
}

int Ship::GetCannons() const {
	return cannons;
}

int Ship::GetCurrentHealth() const {
	return currentHealth;
}

int Ship::GetMaxHealth() const {
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
