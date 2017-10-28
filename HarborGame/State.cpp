#include "stdafx.h"
#include "State.h"

State::~State()
{
	for (size_t i = 0; i < locations.size(); i++)
	{
		delete locations.get(i);
	}
}

bool State::GetQuitState() const
{
	return quit;
}

void State::SetQuitState(bool newState)
{
	quit = newState;
}

Location * State::GetLocation(const String & name) const
{
	for (size_t i = 0; i < locations.size(); i++)
	{
		auto location = locations.get(i);
		auto locname = location->GetName();
		if (locname == name)
			return location;
	}

	return nullptr;
}

Location * State::GetCurrentLocation() const
{
	if (currentLocation < 0)
		return nullptr;

	return locations.get(static_cast<size_t>(currentLocation));
}


void State::NavigateToLocation(const String & locationName, const String& param)
{
	for (size_t i = 0; i < locations.size(); i++)
	{
		auto location = locations.get(i);
		auto locname = location->GetName();

		if (locname == locationName) {
			currentLocation = static_cast<int>(i);

			GetCurrentLocation()->NavigatedTo(param);

			return;
		}
	}
}

void State::LoadShipAssets(const String & filePath)
{
	ships = loader.LoadShips(filePath);
}

void State::LoadHarborAssets(const String & goodsPricesFilePath, const String & goodsAmountsFilePath, const String & harborDistancesFilePath)
{
	harbors = loader.LoadLocations(goodsPricesFilePath, goodsAmountsFilePath, harborDistancesFilePath);
}

Ship * State::GetShip(size_t index)
{
	return &(ships.get(index));
}

Ship * State::GetShip(const String & name)
{
	for (size_t i = 0; i < ships.size(); i++)
	{
		auto& ship = ships.get(i);
		auto& shipname = ship.getName();

		if (shipname == name)
			return &ship;
	}

	return nullptr;
}

Harbor* State::GetHarbor(size_t index)
{
	return &(harbors.get(index));
}

Harbor* State::GetHarbor(const String & name)
{
	for (size_t i = 0; i < harbors.size(); i++)
	{
		auto& harbor = harbors.get(i);
		auto& harborname = harbor.getName();

		if (harborname == name)
			return &harbor;
	}

	return nullptr;
}
