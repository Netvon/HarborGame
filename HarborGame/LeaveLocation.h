#pragma once

#include "String.h"
#include "Option.h"
#include "Location.h"
#include "Harbor.h"

class LeaveLocation : public Location
{
public:
	LeaveLocation() : LeaveLocation("leave") { }
	LeaveLocation(const String& name);
	~LeaveLocation() { };

	void NavigatedTo(const String& param) override;
	void PrintWelcomeMessage() const override;
private:
	void HandleOptionSelected(const Option& option) override;

	Harbor* currentHarbor = nullptr;

};

