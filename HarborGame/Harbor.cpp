#include "stdafx.h"
#include "Harbor.h"

Harbor::~Harbor()
{
}

Vector<Product> Harbor::GetProducts() const {
	return products;
}

const String& Harbor::GetName() const {
	return name;
}
