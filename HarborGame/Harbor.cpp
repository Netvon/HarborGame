#include "stdafx.h"
#include "Harbor.h"

Harbor::~Harbor()
{
}

const Vector<Product>& Harbor::GetProducts() const {
	return products;
}

Vector<Cannon> Harbor::getCannons() const {
	return cannons;
}

Vector<Distance> Harbor::getDistances() const {
	return distances;
}

const String& Harbor::GetName() const {
	return name;
}
