#include "stdafx.h"
#include "Product.h"


Product::Product()
{
}


Product::~Product()
{
}

String Product::getName() const {
	return name;
}

int Product::getMinPrice() const {
	return minPrice;
}

int Product::getMaxPrice() const {
	return maxPrice;
}

int Product::getMinAmountAvailable() const {
	return minAmountAvailable;
}

int Product::getMaxAmountAvailable() const {
	return maxAmountAvailable;
}
