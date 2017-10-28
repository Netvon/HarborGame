#include "stdafx.h"
#include "HarborFactory.h"
#include "Harbor.h"
#include "Product.h"
#include "Distance.h"

#include <iostream>


using std::cout;
using std::endl;


Harbor HarborFactory::CreateHarbor(String& pricesBlueprint, String& amountBlueprint, Vector<String> productNames)
{
	// Variables for the products in a city
	Vector<String> splittedPricesBlueprint{ String::split(pricesBlueprint.c_str(), ";") };
	Vector<String> splittedAmountBlueprint{ String::split(amountBlueprint.c_str(), ";") };

	String name{ splittedPricesBlueprint[0] };
	Vector<Product> products;

	// Adds for each harbor the products
	for (size_t i = 0; i < splittedPricesBlueprint.size(); i++) {
		if (i == 0)
			continue;

		String name{ productNames[i - 1]};
		int minPrice{ String::split(splittedPricesBlueprint[i], "-")[0].toInt() };
		int maxPrice{ String::split(splittedPricesBlueprint[i], "-")[1].toInt() };
		int minAmount{ String::split(splittedAmountBlueprint[i], "-")[0].toInt() };
		int maxAmount{ String::split(splittedAmountBlueprint[i], "-")[1].toInt() };

		Product p{name, minPrice, maxPrice, minAmount, maxAmount};		
	}
	 
	Harbor harbor{ name, products };

	return harbor;
}