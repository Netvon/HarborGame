#include "stdafx.h"
#include "ShopLocation.h"


ShopLocation::ShopLocation(const String & name) : Location(name)
{ }

void ShopLocation::NavigatedTo(const String & param)
{
	ClearOptions();

	AddOption(1, "Leave the shop");
	AddOption(2, "Quit");

	extraMessage = "";

	auto params = String::split(param, ";");
	currentHarbor = GetState().GetHarbor(params.get(0));

	mode = params.get(1);

	if (mode.equals("Ships")) {
		AddShipOptions();
	}
	else if (mode.equals("Goods")) {
		AddGoodsOptions();
	}
	else if (mode.equals("Cannons")) {
		AddCannonOptions();
	}
}

void ShopLocation::AddGoodsOptions()
{
	auto products = currentHarbor->GetProducts();

	for (size_t i = 0; i < products.size(); i++)
	{
		auto product = products.get(i);
		String name = "Buy '";
		name += product.GetName();
		name += "' [ Gold: ";
		name += 10;
		name += " ]";

		AddOption(i + size_t(3), name);
	}
}

void ShopLocation::AddShipOptions()
{
	for (size_t i = 0; i < GetState().GetShipAmount(); i++)
	{
		auto ship = GetState().GetShip(i);
		String name = "Buy '";
		name += ship->GetName();
		name += "' [ Gold: ";
		name += static_cast<int>(ship->GetPrice());
		name += " ] [ ";
		name += static_cast<int>(ship->GetMaxHealth());
		name += " hp ] [ ";
		name += static_cast<int>(ship->GetMaxCargospace());
		name += " goods ] [ ";
		name += static_cast<int>(ship->GetMaxCannons());
		name += " cannons ]";

		AddOption(i + size_t(3), name);
	}

	if (!GetState().GetPlayerHasShip()) {
		extraMessage = "\n| Please note that buying a new ship will sell your current one.\n| You will receive 50% of its value.";
	}
}

void ShopLocation::AddCannonOptions()
{
	for (size_t i = 0; i < currentHarbor->GetCannonSize(); i++)
	{
		auto& cannon = currentHarbor->GetCannon(i);

		String name = "Buy '";
		name += cannon.GetType();
		name += "' [ Gold: ";
		name += cannon.GetPrice();
		name += " ] [ Available: ";
		name += cannon.GetAvailable();
		name += " ]";

		AddOption(i + size_t(3), name);
	}
}

void ShopLocation::PrintWelcomeMessage() const
{
	printf("| Welcome to the %s %s Shop\n", currentHarbor->GetName().c_str(), mode.c_str());

	if (!extraMessage.isEmpty()) {
		printf("%s", extraMessage.c_str());
	}
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

	if (mode.equals("Ships")) {
		size_t shipIndex = option.number - 3u;

		auto ship = GetState().GetShip(shipIndex);
		bool hasEnoughMoney = ship->GetPrice() <= GetState().GetPlayer().GetGold();

		if (!hasEnoughMoney) {
			printf("| I'm afraid you don't have enough money to buy this ship.\n");
		}
		else {

			GetState().GetPlayer().ReplaceShip(ship, 0.5);

			printf("| Enjoy your new '%s' captain, it will be delivered to you soon!\n", ship->GetName().c_str());
			GetState().NavigateToLocation("harbor", currentHarbor->GetName());
		}
	}
	else if (mode.equals("Cannons")) {
		size_t cannonIndex = option.number - 3u;

		auto& cannon = currentHarbor->GetCannon(cannonIndex);
		cannon.DecreaseAmmount(1);

		//GetState().GetPlayer().AddCannonToShip(cannon);
	}
}
