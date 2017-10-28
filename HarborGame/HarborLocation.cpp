#include "stdafx.h"
#include "HarborLocation.h"
#include "State.h"

HarborLocation::HarborLocation()
{
	AddOption(1, "Buy or Sell Goods");
	AddOption(2, "Buy or Sell Cannons");
	AddOption(3, "Buy or Sell a Ship");
	AddOption(4, "Leave");
	AddOption(5, "Repair Ship");
	AddOption(6, "Quit");
}

void HarborLocation::PrintWelcomeMessage() const
{
	printf("Welcome to %s Harbor!\n", currentHarbor->getName().c_str);
}

void HarborLocation::SetCurrentHarbor(const Harbor & current)
{
	currentHarbor = &(const_cast<Harbor&>(current));
}

void HarborLocation::HandleOptionSelected(const Option& option)
{
	printf("Option %i '%s' selected\n", option.number, option.name.c_str());

	switch (option.number)
	{
	case 6:
		State::Instance().SetQuitState(true);
		break;
	default:
		break;
	}
}