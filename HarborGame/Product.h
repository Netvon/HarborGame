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

	Product();
	~Product();

	const String& GetName() const;
	int getMinPrice() const;
	int getMaxPrice() const;
	int GetMinAmountAvailable() const;
	int GetMaxAmountAvailable() const;

	int GetAvailable() const;
	int GetPrice() const;
	void Randomize();

private:
	String name;
	int minPrice;
	int maxPrice;
	int minAmountAvailable;
	int maxAmountAvailable;
	int available;
	int price;
};

