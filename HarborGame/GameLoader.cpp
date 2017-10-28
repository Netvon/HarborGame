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

Vector<Ship> GameLoader::LoadShips() {
	FileParser fileParser;

	Vector<String> allShips{ fileParser.ParseFile("Files/schepen.csv") };

	Vector<Ship> ships;

	for (size_t i = 0; i < allShips.size(); i++) {
		ships.push_back(ShipFactory::CreateShip(allShips.get(i)));
	}

	return ships;
}

Vector<Harbor> GameLoader::LoadLocations() {
	FileParser fileParser;

	Vector<String> allGoodsPrices{ fileParser.ParseFile("Files/goederen prijzen.csv", 0) };
	Vector<String> allGoodsAmount{ fileParser.ParseFile("Files/goederen hoeveelheid.csv", 0) };

	Vector<Harbor> harbors;
	Vector<String> productNames;

	for (size_t i = 0; i < allGoodsPrices.size(); i++) {
		if (i == 0) {
			productNames = String::split(allGoodsPrices[i], ";");
		}
		else {
			harbors.push_back(HarborFactory::CreateHarbor(allGoodsPrices[i], allGoodsAmount[i], productNames));
		}
	}

	return harbors;
}
