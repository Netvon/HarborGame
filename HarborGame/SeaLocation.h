#pragma once
#include "Location.h"
class SeaLocation :
	public Location
{
public:
	SeaLocation();
	~SeaLocation();

	void PrintWelcomeMessage() const override;

	int extradata = 999;

private:
	void HandleOptionSelected(const Option& option) override;
};

