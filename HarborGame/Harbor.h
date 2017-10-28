#include "Product.h"
#include "Distance.h"

#pragma once
class Harbor
{
public:
	Harbor(String name, Vector<Product> products, Vector<Distance> distances) :
		name(name),
		products(products),
		distances(distances)
	{

	};

	Harbor() { };
	~Harbor();

	Vector<Product> getProducts() const;
	Vector<Distance> getDistances() const;
	const String& getName() const;
	void setName(const String& newName);

private:
	Vector<Product> products;
	Vector<Distance> distances;
	String name;
};

