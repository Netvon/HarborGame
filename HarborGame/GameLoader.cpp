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

	for (size_t i = 0; i < allShips.size() - 1; i++) {
		ships.push_back(ShipFactory::CreateShip(allShips.get(i)));
	}

	return ships;
}

Vector<Harbor> GameLoader::LoadLocations() {
	FileParser fileParser;

	Vector<String> allGoodsPrices{ fileParser.ParseFile("Files/goederen prijzen.csv") };
	Vector<String> allGoodsAmount{ fileParser.ParseFile("Files/goederen hoeveelheid.csv") };

	Vector<Harbor> harbors;

	for (size_t i = 0; i < allGoodsPrices.size() - 1; i++) {
		harbors.push_back(HarborFactory::CreateHarbor(allGoodsPrices.get(i), allGoodsAmount.get(i)));
	}

	return harbors;
}
