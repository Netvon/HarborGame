#include "stdafx.h"
#include "RandomNumber.h"
#include <random>

RandomNumber & RandomNumber::Instance()
{
	static RandomNumber instance(time(0));
	return instance;
}

RandomNumber::RandomNumber(int seed)
{
	generator.seed(seed);
}