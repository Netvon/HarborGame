#include "Ship.h"
#include "Harbor.h"

#pragma once
class GameLoader
{
public:
	Vector<Ship> LoadShips(const String& filePath) const;
	Vector<Harbor> LoadLocations(
		const String& goodsPricesFilePath,
		const String& goodsAmountsFilePath,
		const String& harborDistancesFilePath
	) const;
};