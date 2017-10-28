#include "String.h"

#pragma once
class Product
{
public:
	
	Product(int minPrice, int maxPrice, int minAmountAvailable, int maxAmountAvailable) :
		minPrice(minPrice),
		maxPrice(maxPrice),
		minAmountAvailable(minAmountAvailable),
		maxAmountAvailable(maxAmountAvailable) 
		{

		}
	;

	Product();
	~Product();

	const String& getName() const;
	int getMinPrice() const;
	int getMaxPrice() const;
	int getMinAmountAvailable() const;
	int getMaxAmountAvailable() const;

private:
	String name;
	int minPrice;
	int maxPrice;
	int minAmountAvailable;
	int maxAmountAvailable;
};

