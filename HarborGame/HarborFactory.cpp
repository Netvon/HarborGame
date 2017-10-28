#include "stdafx.h"
#include "HarborFactory.h"
#include "Harbor.h"
#include "Product.h"
#include "Distance.h"

Harbor HarborFactory::CreateHarbor(String& pricesBlueprint, String& amountBlueprint, String& distanceBlueprint)
{
	// Variables for the products in a city
	Vector<String> splittedPricesBlueprint{ String::split(pricesBlueprint.c_str(), ";") };
	Vector<String> splittedAmountBlueprint{ String::split(amountBlueprint.c_str(), ";") };

	// Distances between the cities <- nog gedaan worden
	Vector<String> splittedDistanceBlueprint{ String::split(distanceBlueprint.c_str(), ";") };

	String name{ splittedPricesBlueprint.get(0) };
	Vector<Product> products;

	// Hier moet ik nog functionaliteit voor het toevoegen van de min en max dingen

	Harbor harbor{ name, products };

	return harbor;
}