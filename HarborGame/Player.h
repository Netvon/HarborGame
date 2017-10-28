#pragma once
#include "stdafx.h"
#include "Ship.h"

class Player
{
public:
	Player();

	void RepairShip() const;
	void ReplaceShip(Ship& newShip) const;

	const String& GetShipName() const;
	const Ship& GetShip() const;
	const size_t& GetGold() const;

private:
	Ship ship;
	size_t gold;
};

