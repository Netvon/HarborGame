#pragma once
#include "Ship.h"

class ShipFactory
{
public:
	static Ship CreateShip(const String& blueprint);
};

