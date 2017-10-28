#include "stdafx.h"
#include "RandomNumber.h"
#include <random>

RandomNumber & RandomNumber::Instance()
{
	static RandomNumber instance(time(0));
	return instance;
}

size_t RandomNumber::Get(std::size_t min, std::size_t max)
{
	std::uniform_int_distribution<std::size_t> distribution(min, max);
	return distribution(generator);
}

RandomNumber::RandomNumber(int seed)
{
	generator.seed(seed);
}
