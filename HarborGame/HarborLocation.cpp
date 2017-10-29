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
	if (!GetState().GetPlayerHasShip())
		printf("| Welcome to %s Harbor, ...\n| Hold on, you have no ship!\n| You might wanna purchase one in the local shop.\n", currentHarbor->GetName().c_str());
	else
		printf("| Welcome to %s Harbor, captain!\n", currentHarbor->GetName().c_str());
}

void HarborLocation::HandleOptionSelected(const Option& option)
{
	//printf("Option %i '%s' selected\n", option.number, option.name.c_str());

	switch (option.number)
	{
	case 1:
		HandleGoodsShop();
		break;
	case 2:
		if (!GetState().GetPlayerHasShip())
			printf("| Unfortunately you will need a ship to buy these, or where you planning to put a sail on one of these?\n");
		break;
	case 3:
		HandleBuyShip();
		break;
	case 4:
		if (!GetState().GetPlayerHasShip())
			printf("| Without a ship, one cannot sail. You should know that.\n");
		break;
	case 5:
		if (!GetState().GetPlayerHasShip())
			printf("| Are you kidding me? You don't even have a ship laddie.\n");
		else
			GetState().GetPlayer().RepairShip();

		break;
	case 6:
		GetState().SetQuitState(true);
		break;
	default:
		break;
	}
}

void HarborLocation::HandleGoodsShop()
{
	if (!GetState().GetPlayerHasShip()) {
		printf("| Well, I would love to sell you this stuff. However, I do wonder where you will store it...\n");
		return;
	}

	auto harborName = currentHarbor->GetName();
	GetState().NavigateToLocation("shop", harborName + ";Goods");
}

void HarborLocation::HandleBuyShip()
{
	auto harborName = currentHarbor->GetName();
	GetState().NavigateToLocation("shop", harborName + ";Ships");
}
