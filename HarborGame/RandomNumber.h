#pragma once
#include "stdafx.h"
#include <random>
#include <ctime>

class RandomNumber
{
public:
	static RandomNumber & Instance();
	static RandomNumber & Instance(int seed);

	size_t Get(std::size_t min, std::size_t max);
private:
	RandomNumber();
	RandomNumber(int seed);

	std::default_random_engine generator;
};

