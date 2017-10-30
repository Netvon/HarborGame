#include "stdafx.h"
#include "SeaLocation.h"
#include "RandomWeatherGenerator.h"
#include "RandomNumber.h"

SeaLocation::SeaLocation(const String & name) : Location(name)
{
	AddOption(1, "Continue sailing");
	AddOption(2, "View Ship inventory");
	AddOption(3, "Quit");
}

void SeaLocation::NavigatedTo(const String & param) // "destination_harbor_name;distance"
{
	if (GetState().GetLastLocation().equals("leave")) {
		if (param.contains(";")) {
			auto splitted = String::split(param, ";");

			destination = splitted.get(0);
			totalDistance = splitted.get(1).toInt();
			currentDistance = totalDistance;
		}
	}

	currentWeather = RandomWeatherGenerator::Instance().Get();
}

void SeaLocation::PrintWelcomeMessage() const
{
	printf("| Welcome to the open seas, captain.\n| We're on our way to %s and we'll arrive in %i hours.\n", destination.c_str(), currentDistance);	
}

void SeaLocation::HandleOptionSelected(const Option& option)
{
	switch (option.number)
	{
	case 1:
		DoTurn();
		break;
	case 2:
		GenerateShipReport();
		break;
	case 3:
		GetState().SetQuitState(true);
		break;
	}
}

void SeaLocation::GenerateShipReport()
{
	auto& ship = GetState().GetPlayer().GetShip();

	String report = "|[ Your ship: \n|[ === Name ===\n";

	report += "|[ ";
	report += ship.GetName();
	report += "\n|[ === Goods [ ";
	report += to_int(ship.GetUsedCargospace());
	report += "/";
	report += to_int(ship.GetMaxCargospace());
	report += " ] ===\n";

	for (size_t i = 0; i < ship.GetUniqueProductAmount(); i++)
	{
		auto& product = ship.GetProduct(i);
		report += "|[ - ";
		report += product.GetName();
		report += " x ";
		report += product.GetAvailable();
		report += "\n";
	}

	report += "|[ === Cannons [ ";
	report += to_int(ship.GetCannonsAmount());
	report += "/";
	report += to_int(ship.GetMaxCannons());
	report += " ] ===\n";

	for (size_t i = 0; i < ship.GetUniqueCannonAmount(); i++)
	{
		auto& cannon = ship.GetCannon(i);
		report += "|[ - ";
		report += cannon.GetType();
		report += " x ";
		report += cannon.GetAvailable();
		report += "\n";
	}

	printf("%s\n", report.c_str());
}

void SeaLocation::DoTurn()
{
	int battleChance = RandomNumber::Instance().Get<int>(1, 100);

	if (battleChance < 20) {
		printf("{{ insert battle }}\n");
		// GetState().NavigateToLocation("battle");
		// return;
	}

	int oldDistance = currentDistance;
	size_t oldHealth = GetState().GetPlayer().GetShip().GetCurrentHealth();

	HandleWeather();

	int distanceDiff = oldDistance - currentDistance;
	size_t healthDiff = oldHealth - GetState().GetPlayer().GetShip().GetCurrentHealth();

	printf("| The navigator reports the following about the weather: [ %s ].\n\n", GetWeatherFlavour(currentWeather).c_str());

	printf("| Status report;\n");

	if(distanceDiff == 1)
		printf("|\tWe moved fast enough to take [ %i hour off ] our travel time.\n", distanceDiff);
	else if (distanceDiff > 1)
		printf("|\tWe moved fast enough to take [ %i hours off ] our travel time.\n", distanceDiff);
	else if (distanceDiff == -1)
		printf("|\tDue to the weather it will take [ %i hour longer ] to arrive.\n", distanceDiff * -1);
	else if (distanceDiff < 0)
		printf("|\tDue to the weather it will take [ %i hours longer ] to arrive.\n", distanceDiff * -1);
	else
		printf("|\tDue to the weather we didn't move at all.\n");

	printf("|\n");

	if (healthDiff > 0)
		printf("|\tIt looks like we have taken [ %llu damage ] to the hull.\n\n", healthDiff);
	else if(healthDiff == 0 && distanceDiff > 0)
		printf("|\tShe sailed through the weather like a knife through hot butter, cap'n!\n\n");

	if (currentDistance <= 0) {
		GetState().NavigateToLocation("harbor", destination);
	}
}

void SeaLocation::HandleWeather()
{
	currentWeather = RandomWeatherGenerator::Instance().Get();

	switch (currentWeather)
	{
	case WEATHER_NONE:
		return;
	case WEATHER_BREEZE:
		if (GetState().GetPlayer().GetShip().HasLightTrait())
			currentDistance--;
		break;
	case WEATHER_WEAK:
		if (!GetState().GetPlayer().GetShip().HasInertTrait())
			currentDistance--;
		break;
	case WEATHER_NORMAL:
		currentDistance--;
		break;
	case WEATHER_STRONG:
		currentDistance -= 2;
		break;
	case WEATHER_STORM:
		int chance = RandomNumber::Instance().Get<int>(1, 100);

		if (chance < 20) {
			currentDistance--;
		}
		else if (chance > 20 && chance < 60) {
			currentDistance++;
		}
		/*else if (chance > 60 && chance < 100) {
			// do nothting
		}*/

		int damagePercent = RandomNumber::Instance().Get<int>(1, 100);
		int max = GetState().GetPlayer().GetShip().GetCurrentHealth();
		size_t damage = to_sizet(static_cast<float>(max) * (static_cast<float>(damagePercent) / 100.f));

		GetState().GetPlayer().GetShip().SubtractHealth(damage);

		break;
	}
}

String SeaLocation::GetWeatherFlavour(Weather weather) const
{
	switch (weather)
	{
	case WEATHER_NONE:
		return "Nothing to report";
	case WEATHER_BREEZE:
		return "There's a light breeze";
	case WEATHER_WEAK:
		return "The wind is pretty weak";
	case WEATHER_NORMAL:
		return "The weather is nominal";
	case WEATHER_STRONG:
		return "The wind is pretty strong";
	case WEATHER_STORM:
		return "There's a storm brewing, captain";
	}

	return "Nothing to report";
}
