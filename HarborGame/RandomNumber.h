#pragma once
#include "stdafx.h"
#include <random>
#include <ctime>

class RandomNumber
{
public:
	static RandomNumber & Instance();

	template<class T = std::size_t>
	T Get(T min, T max);
private:
	RandomNumber();
	RandomNumber(int seed);

	std::default_random_engine generator;
};

template<class T>
inline T RandomNumber::Get(T min, T max)
{
	std::uniform_int_distribution<T> distribution(min, max);
	return distribution(generator);
}