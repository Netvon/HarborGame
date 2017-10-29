#pragma once

#include "String.h"

class Cannon
{
public:

	Cannon(int price, int minAmount, int maxAmount, String type) :
		price(price),
		minAmountAvailable(minAmount),
		maxAmountAvailable(maxAmount),
		type(type) 
		{

		};

	Cannon();

	int GetPrice() const;
	int getMinAmountAvailable() const;
	int getMaxAmountAvailable() const;
	String getType() const;
private:
	int price;
	int minAmountAvailable;
	int maxAmountAvailable;
	String type;
};

