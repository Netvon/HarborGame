#pragma once
#include "String.h"

class Ship
{
public:
	Ship();

	Ship(String name,
		int price,
		int cargospace,
		int cannons,
		int maxHealth,
		bool hasTinyTrait,
		bool hasInertTrait,
		bool hasLightTrait) :
		name(name),
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

	const String& getName() const;
	int getPrice() const;
	int getCargospace() const;
	int getCannons() const;
	int getCurrentHealth() const;
	int getMaxHealth() const;
	bool getTinyTrait() const;
	bool getInertTrait() const;
	bool getLightTrait() const;

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



