#include "String.h"

#pragma once
class Product
{
public:
	
	Product(String name, int minPrice, int maxPrice, int minAmountAvailable, int maxAmountAvailable) :
		name(name),
		minPrice(minPrice),
		maxPrice(maxPrice),
		minAmountAvailable(minAmountAvailable),
		maxAmountAvailable(maxAmountAvailable),
		available (0)
		{

		}
	;

	Product(const Product & other, size_t newAmount);

	Product();
	
	int GetMinPrice() const;
	int GetMaxPrice() const;
	int GetMinAmountAvailable() const;
	int GetMaxAmountAvailable() const;

	int GetAvailable() const;
	int GetPrice() const;

	void Randomize();

	void DecreaseAmount(int amount);
	void IncreaseAmount(int amount);

	const String& GetName() const;

private:
	String name;
	int minPrice;
	int maxPrice;
	int minAmountAvailable;
	int maxAmountAvailable;
	int available;
	int price;
};

