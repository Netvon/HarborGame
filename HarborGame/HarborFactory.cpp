#include "stdafx.h"
#include "HarborFactory.h"
#include "Harbor.h"
#include "Product.h"
#include "Distance.h"

#include <iostream>


using std::cout;
using std::endl;


Harbor HarborFactory::CreateHarbor(String& pricesBlueprint, String& amountBlueprint, String& distancesBlueprint, Vector<String> productNames, Vector<String> harborNames)
{
	// Variables for the products in a city
	Vector<String> splittedPricesBlueprint{ String::split(pricesBlueprint.c_str(), ";") };
	Vector<String> splittedAmountBlueprint{ String::split(amountBlueprint.c_str(), ";") };
	Vector<String> splittedDistancesBlueprint{ String::split(distancesBlueprint.c_str(), ";") };

	String name{ splittedPricesBlueprint[0] };
	Vector<Product> products;
	Vector<Distance> distances;

	// Adds for each harbor the products and distances
	for (size_t i = 0; i < splittedPricesBlueprint.size(); i++) {
		if (i == 0)
			continue;

		// First the products
		String pName{ productNames[i - 1]};
		int minPrice{ String::split(splittedPricesBlueprint[i], "-")[0].toInt() };
		int maxPrice{ String::split(splittedPricesBlueprint[i], "-")[1].toInt() };
		int minAmount{ String::split(splittedAmountBlueprint[i], "-")[0].toInt() };
		int maxAmount{ String::split(splittedAmountBlueprint[i], "-")[1].toInt() };

		Product p{ pName, minPrice, maxPrice, minAmount, maxAmount};
		products.push_back(p);

		// Second the distances; without the distance to your harbor
		if (harborNames[i - 1] != name) {
			String hName{ harborNames[i - 1] };
			size_t distance{ static_cast<size_t>(splittedDistancesBlueprint[i].toInt()) };

			Distance d{ hName, distance };
			distances.push_back(d);
		}
	}
	 
	Harbor harbor{ name, products, distances };


	cout << "Name: " << harbor.getName() << endl;

	cout << "Producten: " << endl;
	for (size_t i = 0; i < harbor.getProducts().size(); i++)
	{
		cout << harbor.getProducts()[i].getName() << endl;
	}

	cout << "Distances: " << endl;
	for (size_t i = 0; i < harbor.getDistances().size(); i++)
	{
		cout << harbor.getDistances()[i].getTo() << ": " << harbor.getDistances()[i].getDistance() << endl;
	}

	return harbor;
}