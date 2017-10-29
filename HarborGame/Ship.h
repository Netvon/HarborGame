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
		{ };

	Ship(Ship * other);

	~Ship();

	void setCurrentHealth(int pCurrentHealth);

	const String& GetName() const;

	int GetPrice() const;
	int GetMaxCargospace() const;
	int GetCannons() const;
	int GetCurrentHealth() const;
	int GetMaxHealth() const;
	bool GetTinyTrait() const;
	bool GetInertTrait() const;
	bool GetLightTrait() const;

	bool operator==(Ship* other);
	bool operator!=(Ship* other);

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
