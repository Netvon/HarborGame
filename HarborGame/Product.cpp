#include "stdafx.h"
#include "Product.h"
#include "RandomNumber.h"

Product::Product(const Product & other, size_t newAmount)
{
	name = other.name;
	minAmountAvailable = other.minAmountAvailable;
	maxAmountAvailable = other.maxAmountAvailable;
	minPrice = other.minPrice;
	maxPrice = other.maxPrice;
	available = static_cast<int>(newAmount);
	price = other.price;
}

Product::Product() { }

const String& Product::GetName() const {
	return name;
}

int Product::GetMinPrice() const {
	return minPrice;
}

int Product::GetMaxPrice() const {
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
	available = RandomNumber::Instance().Get<int>(minAmountAvailable, maxAmountAvailable);
	price = RandomNumber::Instance().Get<int>(minPrice, maxPrice);
}

void Product::DecreaseAmount(int amount)
{
	available -= amount;

	if (available < 0) available = 0;
}

void Product::IncreaseAmount(int amount)
{
	available += amount;
}
