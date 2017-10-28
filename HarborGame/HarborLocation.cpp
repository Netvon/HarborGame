#include "stdafx.h"
#include "HarborLocation.h"
#include "State.h"

#include <iostream>
#include "GameLoader.h"

HarborLocation::HarborLocation(const String& name) : Location(name)
{
	AddOption(1, "Buy or Sell Goods");
	AddOption(2, "Buy or Sell Cannons");
	AddOption(3, "Buy or Sell a Ship");
	AddOption(4, "Leave");
	AddOption(5, "Repair Ship");
	AddOption(6, "Quit");
}

void HarborLocation::NavigatedTo(const String & param)
{
	currentHarbor = GetState().GetHarbor(param);
}

void HarborLocation::PrintWelcomeMessage() const
{
	printf("Welcome to %s Harbor, traveler!\n", currentHarbor->getName().c_str());
}

void HarborLocation::HandleOptionSelected(const Option& option)
{
	printf("Option %i '%s' selected\n", option.number, option.name.c_str());

	switch (option.number)
	{
	case 6:
		GetState().SetQuitState(true);
		break;
	default:
		break;
	}
}