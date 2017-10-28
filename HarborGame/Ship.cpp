#include "stdafx.h"
#include "Ship.h"

Ship::Ship()
{

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

int Ship::getPrice() const {
	return price;
}

int Ship::getCargospace() const {
	return cargospace;
}

int Ship::getCannons() const {
	return cannons;
}

int Ship::getCurrentHealth() const {
	return currentHealth;
}

int Ship::getMaxHealth() const {
	return maxHealth;
}

bool Ship::getTinyTrait() const {
	return hasTinyTrait;
}

bool Ship::getInertTrait() const {
	return hasInertTrait;
}

bool Ship::getLightTrait() const {
	return hasLightTrait;
}
