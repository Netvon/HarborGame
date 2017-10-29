#include "stdafx.h"
#include "GameLoader.h"
#include "FileParser.h"
#include "ShipFactory.h"
#include "HarborFactory.h"

GameLoader::GameLoader()
{
	
}


GameLoader::~GameLoader()
{
	
}

Vector<Ship> GameLoader::LoadShips(const String& filePath) { // "Files/schepen.csv"
	FileParser fileParser;

	Vector<String> allShips{ fileParser.ParseFile(filePath) };

	Vector<Ship> ships;

	for (size_t i = 0; i < allShips.size(); i++) {
		ships.push_back(ShipFactory::CreateShip(allShips.get(i)));
	}

	return ships;
}

Vector<Harbor> GameLoader::LoadLocations(const String & goodsPricesFilePath, const String & goodsAmountsFilePath, const String & harborDistancesFilePath)
{
	FileParser fileParser;

	Vector<String> allGoodsPrices{ fileParser.ParseFile(goodsPricesFilePath, 0) };
	Vector<String> allGoodsAmount{ fileParser.ParseFile(goodsAmountsFilePath, 0) };
	Vector<String> allDistances{ fileParser.ParseFile(harborDistancesFilePath, 0) };

	Vector<Harbor> harbors;
	Vector<String> productNames;
	Vector<String> harborNames;

	for (size_t i = 0; i < allGoodsPrices.size(); i++) {
		if (i == 0) {
			productNames = String::split(allGoodsPrices[i], ";");
			harborNames = String::split(allDistances[i], ";");
		}
		else {
			harbors.push_back(HarborFactory::CreateHarbor(allGoodsPrices[i], allGoodsAmount[i], allDistances[i], productNames, harborNames));
		}
	}

	return harbors;
}


