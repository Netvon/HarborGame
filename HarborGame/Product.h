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
		maxAmountAvailable(maxAmountAvailable) 
		{

		}
	;

	Product();
	~Product();

	const String& GetName() const;
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

