#pragma once

#include "String.h"

class Cannon
{
public:

	Cannon(int price, int minAmount, int maxAmount, const String& type) :
		price(price),
		minAmountAvailable(minAmount),
		maxAmountAvailable(maxAmount),
		type(type) 
		{

		};

	Cannon(const Cannon& other);

	Cannon();

	int GetPrice() const;
	int GetMinAmountAvailable() const;
	int GetMaxAmountAvailable() const;

	int GetAvailable() const;

	bool IsHeavy() const;

	void RandomizeAvailable();

	void DecreaseAmmount(int amount);
	void IncreaseAmmount(int amount);

	String GetType() const;
private:
	int price;
	int minAmountAvailable;
	int maxAmountAvailable;

	int available;
	String type;
};

