#pragma once
#include "Ship.h"

class ShipFactory
{
public:
	ShipFactory();
	~ShipFactory();

	Ship CreateShip(String& blueprint);
};

