#include "stdafx.h"
#include "Product.h"
#include "RandomNumber.h"

Product::Product()
{
}


Product::~Product()
{
}

const String& Product::GetName() const {
	return name;
}

int Product::getMinPrice() const {
	return minPrice;
}

int Product::getMaxPrice() const {
	return maxPrice;
}

int Product::GetMinAmountAvailable() const {
	return minAmountAvailable;
}

int Product::GetMaxAmountAvailable() const {
	return maxAmountAvailable;
}

int Product::GetAvailable() const
{
	return available;
}

int Product::GetPrice() const
{
	return price;
}

void Product::Randomize()
{
	available = RandomNumber::Instance().Get(minAmountAvailable, maxAmountAvailable);
	price = RandomNumber::Instance().Get(minPrice, maxPrice);
}
