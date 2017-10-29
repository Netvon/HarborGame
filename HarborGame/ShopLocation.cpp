#include "stdafx.h"
#include "ShopLocation.h"


ShopLocation::ShopLocation(const String & name) : Location(name)
{
	AddOption(1, "Leave the shop");
	AddOption(2, "Quit");
}

void ShopLocation::NavigatedTo(const String & param)
{
	auto params = String::split(param, ";");
	currentHarbor = GetState().GetHarbor(params.get(0));

	mode = params.get(1);
}

void ShopLocation::PrintWelcomeMessage() const
{
	printf("| Welcome to the %s %s Shop\n", currentHarbor->GetName().c_str(), mode.c_str());
}

void ShopLocation::HandleOptionSelected(const Option & option)
{
	switch (option.number)
	{
	case 1:
		GetState().NavigateToLocation("harbor", currentHarbor->GetName());
		break;
	case 2:
		GetState().SetQuitState(true);
		break;
	default:
		break;
	}
}
