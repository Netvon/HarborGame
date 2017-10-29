#include "stdafx.h"
#include "ShipFactory.h"

Ship ShipFactory::CreateShip(const String& blueprint) 
{
	if (blueprint.isEmpty())
		throw "Cannot create Ship from empty blueprint";

	Vector<String> splittedBlueprint{ String::split(blueprint.c_str(), ";") };

	if (splittedBlueprint.size() < 5)
		throw "Blueprint string does not contain enough parts to create a Ship";

	if (splittedBlueprint.size() == 5)
		splittedBlueprint.push_back("");

	String& name = splittedBlueprint[0];
	size_t price{ splittedBlueprint[1].toSizeT() };
	size_t cargospace{ splittedBlueprint[2].toSizeT() };
	size_t cannons{ splittedBlueprint[3].toSizeT() };
	size_t maxHealth{ splittedBlueprint[4].toSizeT() };

	bool hasTinyTrait{ splittedBlueprint.get(5).contains("klein") };
	bool hasInertTrait{ splittedBlueprint.get(5).contains("log") };
	bool hasLightTrait{ splittedBlueprint.get(5).contains("licht") };

	return { name, price, cargospace, cannons, maxHealth, hasTinyTrait, hasInertTrait, hasLightTrait };
}
