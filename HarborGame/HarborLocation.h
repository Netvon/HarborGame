#pragma once
#include "Location.h"
class HarborLocation :
	public Location
{
public:
	HarborLocation();
	~HarborLocation() { };

	void PrintWelcomeMessage() const override;

private:
	void HandleOptionSelected(Option option) override;
};

