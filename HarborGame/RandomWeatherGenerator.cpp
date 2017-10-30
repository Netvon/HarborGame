#include "stdafx.h"
#include "RandomWeatherGenerator.h"
#include "RandomNumber.h"

RandomWeatherGenerator & RandomWeatherGenerator::Instance()
{
	static RandomWeatherGenerator instance;
	return instance;
}

Weather RandomWeatherGenerator::Get() const
{
	auto roll = RandomNumber::Instance().Get<int>(1, 20);

	if (NumberBetween(1, 2, roll)) {
		return WEATHER_NONE;
	}
	else if (NumberBetween(3, 4, roll)) {
		return WEATHER_BREEZE;
	}
	else if (NumberBetween(5, 7, roll)) {
		return WEATHER_WEAK;
	}
	else if (NumberBetween(8, 17, roll)) {
		return WEATHER_NORMAL;
	}
	else if (NumberBetween(18, 19, roll)) {
		return WEATHER_STORM;
	}

	return WEATHER_NONE;
}

bool RandomWeatherGenerator::NumberBetween(int min, int max, int number) const
{
	return number >= min && number <= max;
}
