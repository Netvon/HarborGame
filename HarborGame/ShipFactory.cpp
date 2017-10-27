#include "stdafx.h"
#include "ShipFactory.h"

using namespace std;

ShipFactory::ShipFactory()
{

}


ShipFactory::~ShipFactory()
{

}

Ship ShipFactory::CreateShip(String& blueprint) 
{
	Vector<String> splittedBlueprint{ String::split(blueprint.c_str(), ";") };

	String name{ splittedBlueprint.get(0).c_str() };
	int price{ atoi(splittedBlueprint.get(1).c_str()) };
	int cargospace{ atoi(splittedBlueprint.get(2).c_str()) };
	int cannons{ atoi(splittedBlueprint.get(3).c_str()) };
	int maxHealth{ atoi(splittedBlueprint.get(4).c_str()) };
	bool hasTinyTrait{ splittedBlueprint.get(5).contains("klein") };
	bool hasInertTrait{ splittedBlueprint.get(5).contains("log") };
	bool hasLightTrait{ splittedBlueprint.get(5).contains("licht") };

	Ship ship { name, price, cargospace, cannons, maxHealth, hasTinyTrait, hasInertTrait, hasLightTrait };

	return ship;
}
