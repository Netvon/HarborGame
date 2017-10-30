#pragma once
#include "Ship.h"

class RandomPirateshipGenerator
{
public:
	static RandomPirateshipGenerator & Instance();

	static Ship GeneratePirateship(const Vector<Ship>& ships);
private:
	RandomPirateshipGenerator();
};

