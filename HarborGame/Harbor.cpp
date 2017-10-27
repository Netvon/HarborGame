#include "stdafx.h"
#include "Harbor.h"

Harbor::~Harbor()
{
}

Vector<Product> Harbor::getProducts() const {
	return products;
}

String Harbor::getName() const {
	return name;
}