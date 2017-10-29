#include "stdafx.h"
#include "Cannon.h"


Cannon::Cannon()
{
}

int Cannon::GetPrice() const {
	return price;
}

int Cannon::getMinAmountAvailable() const {
	return minAmountAvailable;
}

int Cannon::getMaxAmountAvailable() const {
	return maxAmountAvailable;
}

String Cannon::getType() const {
	return type;
}
