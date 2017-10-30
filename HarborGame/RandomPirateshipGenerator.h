#pragma once
#include "Ship.h"

class RandomPirateshipGenerator
{
public:
	static RandomPirateshipGenerator & Instance();

	Ship GeneratePirateship(const Vector<Ship>& ships) const;
private:
	RandomPirateshipGenerator() {};
};

