#include "stdafx.h"
#include "Ship.h"


Ship::~Ship()
{

}

void Ship::setCurrentHealth(int pCurrentHealth) {
	currentHealth = pCurrentHealth;
}

int Ship::getCurrentHealth() const {
	return currentHealth;
}