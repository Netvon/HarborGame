#pragma once
#include "stdafx.h"
#include "Ship.h"

class Player
{
public:
	Player();
	~Player()
	{
		delete ship;
	}

	void RepairShip(size_t gold, size_t steps);
	void ReplaceShip(Ship* newShip, double retainMultiplier);
	void AddGold(size_t addGoldAmount);
	void SubtractGold(size_t subtractAmount);

	const String& GetShipName() const;
	Ship& GetShip() const;
	const size_t& GetGold() const;

	bool GetIsBroke() const;

	void AddCannonToShip(Cannon& cannon);

private:
	Ship* ship = nullptr;
	size_t gold;
};

