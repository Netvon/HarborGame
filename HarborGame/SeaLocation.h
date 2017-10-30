#pragma once
#include "Location.h"
#include "String.h"
#include "Distance.h"

class SeaLocation :
	public Location
{
public:
	SeaLocation() : SeaLocation("sea") { }
	SeaLocation(const String& name);
	~SeaLocation() { };

	void NavigatedTo(const String& param) override;
	void PrintWelcomeMessage() const override;

private:
	void HandleOptionSelected(const Option& option) override;
	Distance distance;
	size_t turn;
};

