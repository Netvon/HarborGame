#include "stdafx.h"
#include "HarborFactory.h"
#include "Harbor.h"
#include "Product.h"
#include "Distance.h"

#include <iostream>


using std::cout;
using std::endl;


Harbor HarborFactory::CreateHarbor(String& pricesBlueprint, String& amountBlueprint)
{
	// Variables for the products in a city
	Vector<String> splittedPricesBlueprint{ String::split(pricesBlueprint.c_str(), ";") };
	Vector<String> splittedAmountBlueprint{ String::split(amountBlueprint.c_str(), ";") };

	String name{ splittedPricesBlueprint.get(0) };
	Vector<Product> products;

	// Loop for splitting the product tables and adding those to the harbor
	for (size_t i = 0; i < splittedPricesBlueprint.size(); i++) {
		String name{};
		int minPrice{ String::split(splittedPricesBlueprint.get(i), "-").get(0).toInt() };
		int maxPrice{ String::split(splittedPricesBlueprint.get(i), "-").get(1).toInt() };
		int minAmount{ String::split(splittedAmountBlueprint.get(i), "-").get(0).toInt() };
		int maxAmount{ String::split(splittedAmountBlueprint.get(i), "-").get(1).toInt() };

		Product p{minPrice, maxPrice, minAmount, maxAmount};
		//cout << p.getName() << endl;
	}


	// Hier moet ik nog functionaliteit voor het toevoegen van de min en max dingen

	Harbor harbor{ name, products };

	return harbor;
}