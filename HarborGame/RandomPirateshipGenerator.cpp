#include "stdafx.h"
#include "RandomPirateshipGenerator.h"
#include "RandomNumber.h"
#include <random>

RandomPirateshipGenerator & RandomPirateshipGenerator::Instance()
{
	static RandomPirateshipGenerator instance;
	return instance;
}

Ship RandomPirateshipGenerator::GeneratePirateship(const Vector<Ship>& ships)
{
	size_t shipIndex = RandomNumber::Instance().Get<size_t>(0, ships.size());

	auto& pirateship = ships.get(shipIndex);
	size_t maxAmountOfCannons = pirateship.GetMaxCannons();

	size_t amountOfCannons = RandomNumber::Instance().Get<size_t>(maxAmountOfCannons / 2, maxAmountOfCannons);

	// generating amount of small cannons
	size_t amountOfSmallCannons = RandomNumber::Instance().Get<size_t>(amountOfCannons / 2, amountOfCannons);
	pirateship.AddCannon("licht kannon", amountOfSmallCannons);

	amountOfCannons -= amountOfSmallCannons;
	// generating amount of medium cannons
	size_t amountOfMediumCannons = RandomNumber::Instance().Get<size_t>(amountOfCannons / 2, amountOfCannons);
	pirateship.AddCannon("middelgroot kannon", amountOfMediumCannons);

	amountOfCannons -= amountOfMediumCannons;
	// generating amount of medium cannons; if possible
	if (!pirateship.HasTinyTrait())
	{
		size_t amountOfHeavyCannons = RandomNumber::Instance().Get<size_t>(amountOfCannons / 2, amountOfCannons);
		pirateship.AddCannon("zwaar kannon", amountOfHeavyCannons);
	}	

	return pirateship;
}

