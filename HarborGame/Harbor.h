#include "Product.h"
#include "Cannon.h"
#include "Distance.h"

#pragma once
class Harbor
{
public:
	Harbor(String name, Vector<Product> products, Vector<Cannon> cannons, Vector<Distance> distances) :
		name(name),
		products(products),
		cannons(cannons),
		distances(distances)
	{

	};

	Harbor() { };
	~Harbor();

	Vector<Product> getProducts() const;
	Vector<Cannon> getCannons() const;
	Vector<Distance> getDistances() const;
	const String& getName() const;
	void setName(const String& newName);

private:
	Vector<Product> products;
	Vector<Cannon> cannons;
	Vector<Distance> distances;
	String name;
};

