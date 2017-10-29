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

	if (mode.equals("Ships")) {
		for (size_t i = 0; i < GetState().GetShipAmount(); i++)
		{
			auto ship = GetState().GetShip(i);
			String name = "Buy '";
			name += ship->GetName();
			name += "' [ Gold: ";
			name += ship->getPrice();
			name += " ]";

			AddOption(i + 3u,  name);
		}
	}
	else if (mode.equals("Goods")) {
		auto products = currentHarbor->GetProducts();

		for (size_t i = 0; i < products.size(); i++)
		{
			auto product = products.get(i);
			String name = "Buy '";
			name += product.GetName();
			name += "' [ Gold: ";
			name += 10;
			name += " ]";

			AddOption(i + 3u, name);
		}
	}
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
		return;
	case 2:
		GetState().SetQuitState(true);
		return;
	default:
		break;
	}
}
