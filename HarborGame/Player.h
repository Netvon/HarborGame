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

	void RepairShip() const;
	void ReplaceShip(Ship& newShip) const;

	const String& GetShipName() const;
	Ship& GetShip() const;
	const size_t& GetGold() const;

private:
	Ship* ship = nullptr;
	size_t gold;
};

