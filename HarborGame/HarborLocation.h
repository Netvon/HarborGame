#pragma once
#include "Location.h"
#include "Product.h"
#include "Harbor.h"

class HarborLocation :
	public Location
{
public:
	HarborLocation();
	~HarborLocation() { };

	void PrintWelcomeMessage() const override;
	void SetCurrentHarbor(const Harbor& current);
	
private:
	void HandleOptionSelected(const Option& option) override;
	Harbor* currentHarbor = nullptr;
};

