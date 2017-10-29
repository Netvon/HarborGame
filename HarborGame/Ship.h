#pragma once
#include "String.h"
#include "Cannon.h"

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
	bool HasTinyTrait() const;
	bool HasInertTrait() const;
	bool HasLightTrait() const;

	bool GetIsAtFullHealth() const;
	size_t GetUniqueCannonAmount() const;

	bool operator==(Ship* other);
	bool operator!=(Ship* other);

	void SubtractHealth(size_t amount = 1);
	void AddHealth(size_t amount = 1);

	void AddCannon(const Cannon& newCannon);
	void RemoveCannon(Cannon& cannon);

	Cannon& GetCannon(size_t index);

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

	Vector<Cannon> cannonList;
};
