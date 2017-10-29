#pragma once
#include "String.h"

class Ship
{
public:
	Ship();

	Ship(String name,
		size_t price,
		size_t maxCargospace,
		size_t maxCannons,
		size_t maxHealth,
		bool hasTinyTrait,
		bool hasInertTrait,
		bool hasLightTrait) :
		name(name),
		price(price),
		maxCargospace(maxCargospace),
		maxCannons(maxCannons),
		maxHealth(maxHealth),
		currentHealth(maxHealth),
		hasTinyTrait(hasTinyTrait),
		hasInertTrait(hasInertTrait),
		hasLightTrait(hasLightTrait)
		{ };

	Ship(Ship * other);

	const String& GetName() const;

	size_t GetPrice() const;
	size_t GetMaxCargospace() const;
	size_t GetUsedCargospace() const;
	size_t GetMaxCannons() const;
	size_t GetCannonsAmount() const;
	size_t GetCurrentHealth() const;
	size_t GetMaxHealth() const;
	bool GetTinyTrait() const;
	bool GetInertTrait() const;
	bool GetLightTrait() const;

	bool GetIsAtFullHealth() const;

	bool operator==(Ship* other);
	bool operator!=(Ship* other);

	void SubtractHealth(size_t amount = 1);
	void AddHealth(size_t amount = 1);

private:
	String name;
	size_t price;
	size_t cargospace;
	size_t maxCargospace;
	size_t cannons;
	size_t maxCannons;
	size_t currentHealth;
	size_t maxHealth;
	bool hasTinyTrait;
	bool hasInertTrait;
	bool hasLightTrait;
};
