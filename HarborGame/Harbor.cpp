#include "stdafx.h"
#include "Harbor.h"

Harbor::~Harbor()
{
}

Vector<Product> Harbor::getProducts() const {
	return products;
}

Vector<Cannon> Harbor::getCannons() const {
	return cannons;
}

Vector<Distance> Harbor::getDistances() const {
	return distances;
}

const String& Harbor::getName() const {
	return name;
}

void Harbor::setName(const String & newName)
{
	name = newName;
}
