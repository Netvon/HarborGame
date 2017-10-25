#pragma once
#include "String.h"

class Ship
{
public:
	Ship(String& name,
		int price,
		int cargospace,
		int cannons,
		int maxHealth,
		bool hasTinyTrait,
		bool hasInertTrait,
		bool hasLightTrait) :
		price(price),
		cargospace(cargospace),
		cannons(cannons),
		maxHealth(maxHealth),
		currentHealth(maxHealth),
		hasTinyTrait(hasTinyTrait),
		hasInertTrait(hasInertTrait),
		hasLightTrait(hasLightTrait)
		{

		};

	~Ship();

	void setCurrentHealth(int pCurrentHealth);

	int getCurrentHealth() const;

private:
	String name;
	int price;
	int cargospace;
	int cannons;
	int currentHealth;
	int maxHealth;
	bool hasTinyTrait;
	bool hasInertTrait;
	bool hasLightTrait;
};



