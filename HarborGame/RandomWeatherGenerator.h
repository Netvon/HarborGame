#pragma once
#include "stdafx.h"
#include "Weather.h"

class RandomWeatherGenerator
{
public:
	static RandomWeatherGenerator & Instance();
	Weather Get() const;

private:
	RandomWeatherGenerator() { };

	bool NumberBetween(int min, int max, int number) const;
};

