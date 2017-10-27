#include "stdafx.h"
#include "GameLoader.h"
#include "FileParser.h"
#include "ShipFactory.h"
#include "HarborFactory.h"

using namespace std;

GameLoader::GameLoader()
{
	
}


GameLoader::~GameLoader()
{
	
}

Vector<Ship> GameLoader::LoadShips() {
	ShipFactory shipFactory;
	FileParser fileParser;

	Vector<String> allShips{ fileParser.ParseFile("Files/schepen.csv") };

	Vector<Ship> ships;

	for (size_t i = 0; i < allShips.size() - 1; i++) {
		ships.push_back(shipFactory.CreateShip(allShips.get(i)));
	}

	return ships;
}

Vector<Harbor> GameLoader::LoadLocations() {
	HarborFactory harborFactory;
	FileParser fileParser;

	Vector<String> allGoodsPrices{ fileParser.ParseFile("Files/goederen prijzen.csv") };

	Vector<Harbor> harbors;

	for (size_t i = 0; i < allGoodsPrices.size() - 1; i++) {
		harbors.push_back(harborFactory.CreateHarbor(allGoodsPrices.get(i)));
	}

	return harbors;
}
