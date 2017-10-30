#include "stdafx.h"
#include "SeaLocation.h"
#include "RandomWeatherGenerator.h"
#include "RandomNumber.h"

SeaLocation::SeaLocation(const String & name) : Location(name)
{
	AddOption(1, "Set Sail");
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
	printf("| Welcome to the open seas, captain.\n| We're on our way to %s and we'll arrive in %i turns.\n", destination.c_str(), currentDistance);
	printf("| The navigator reports the following about the weather: %s.\n", GetWeatherFlavour(currentWeather).c_str());
}

void SeaLocation::HandleOptionSelected(const Option& option)
{
	switch (option.number)
	{
	case 1:
		DoTurn();
		break;
	case 2:
		break;
	case 3:
		GetState().SetQuitState(true);
		break;
	}
}

void SeaLocation::DoTurn()
{
	int oldDistance = currentDistance;
	size_t oldHealth = GetState().GetPlayer().GetShip().GetCurrentHealth();

	HandleWeather();

	int distanceDiff = oldDistance - currentDistance;
	size_t healthDiff = oldHealth - GetState().GetPlayer().GetShip().GetCurrentHealth();

	printf("| Status report. We moved %i steps and we have taken %llu damage!\n", distanceDiff, healthDiff);

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
