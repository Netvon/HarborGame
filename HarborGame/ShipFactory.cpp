#include "stdafx.h"
#include "ShipFactory.h"

Ship ShipFactory::CreateShip(const String& blueprint) 
{
	if (blueprint.isEmpty())
		throw "Cannot create Ship from empty blueprint";

	Vector<String> splittedBlueprint{ String::split(blueprint.c_str(), ";") };

	if (splittedBlueprint.size() != 6)
		throw "Blueprint string does not contain enough parts to create a Ship";

	String& name = splittedBlueprint[0];
	int price{ splittedBlueprint[1].toInt() };
	int cargospace{ atoi(splittedBlueprint.get(2).c_str()) };
	int cannons{ atoi(splittedBlueprint.get(3).c_str()) };
	int maxHealth{ atoi(splittedBlueprint.get(4).c_str()) };
	bool hasTinyTrait{ splittedBlueprint.get(5).contains("klein") };
	bool hasInertTrait{ splittedBlueprint.get(5).contains("log") };
	bool hasLightTrait{ splittedBlueprint.get(5).contains("licht") };

	return { name, price, cargospace, cannons, maxHealth, hasTinyTrait, hasInertTrait, hasLightTrait };
}
