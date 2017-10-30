#include "Ship.h"
#include "Harbor.h"

#pragma once
class GameLoader
{
public:
	GameLoader();
	~GameLoader();

	Vector<Ship> LoadShips(const String& filePath);
	Vector<Harbor> LoadLocations(
		const String& goodsPricesFilePath,
		const String& goodsAmountsFilePath,
		const String& harborDistancesFilePath
	);

private:
	

};