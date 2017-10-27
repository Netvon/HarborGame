#include "stdafx.h"
#include "GameLoader.h"
#include "FileParser.h"
#include "ShipFactory.h"

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

	Vector<String> AllLines{ fileParser.ParseFile("Files/schepen.csv") };

	Vector<Ship> ships;

	for (size_t i = 0; i < AllLines.size() - 1; i++) {
		ships.push_back(shipFactory.CreateShip(AllLines.get(i)));
	}

	return ships;
}

