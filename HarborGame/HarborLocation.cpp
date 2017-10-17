#include "stdafx.h"
#include "HarborLocation.h"
#include "State.h"

HarborLocation::HarborLocation() : Location(5)
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
	printf("Welcome to the Harbor!\n");
}

void HarborLocation::HandleOptionSelected(Option option)
{
	printf("Option %i '%s' selected\n", option.number, option.name);

	switch (option.number)
	{
	case 6:
		State::Instance()->SetQuitState(true);
		break;
	default:
		break;
	}
}
