#include "stdafx.h"
#include "Harbor.h"

Harbor::~Harbor()
{
}

Vector<Product> Harbor::getProducts() const {
	return products;
}

const String& Harbor::getName() const {
	return name;
}

void Harbor::setName(const String & newName)
{
	name = newName;
}