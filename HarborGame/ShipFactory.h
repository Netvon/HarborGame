#pragma once
#include "Ship.h"

class ShipFactory
{
public:
	static Ship CreateShip(String& blueprint);
private:
	ShipFactory() {};
};

